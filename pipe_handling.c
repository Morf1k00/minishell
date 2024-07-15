/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:35:37 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/05 11:58:59 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_child_process(int prev_fd[2], int *pipe_fd,
	char **arv, t_env_path *env_shell)
{
	char	**cmd_args;

	if (prev_fd[0] != -1)
	{
		dup2(prev_fd[0], STDIN_FILENO);
		close(prev_fd[0]);
	}
	if (pipe_fd[1] != -1)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	close(pipe_fd[0]);
	setup_redirections(&arv[prev_fd[1]]);
	cmd_args = extract_cmd(arv[prev_fd[1]], env_shell->path);
	if (execve(cmd_args[0], &arv[prev_fd[1]], env_shell->env_paths) == -1)
	{
		perror("execve");
		exit(127);
	}
	free(cmd_args);
}

void	setup_pipes(int cmd_index, int num_commands, int *pipe_fd)
{
	if (cmd_index < num_commands - 1)
		create_pipe(pipe_fd);
	else
	{
		pipe_fd[0] = -1;
		pipe_fd[1] = -1;
	}
}

void	find_next_command(char **arv, int *i)
{
	while (arv[*i] && strcmp(arv[*i], "|") != 0)
		(*i)++;
	arv[*i] = NULL;
}

void	execute_commands(int num_commands, char **arv,
		int test[2], t_env_path *env_shell)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		i;
	int		cmd_index;

	i = 0;
	cmd_index = 0;
	while (cmd_index < num_commands)
	{
		setup_pipes(cmd_index, num_commands, pipe_fd);
		find_next_command(arv, &i);
		pid = fork();
		if (pid == 0)
			handle_child_process(test, pipe_fd, arv, env_shell);
		close_pipes(test[0], pipe_fd);
		test[0] = pipe_fd[0];
		test[1] = ++i;
		cmd_index++;
	}
}

int	execute_pipe(t_env_path *data, char **arv, int num_commands)
{
	int	status;
	int	test[2];

	test[0] = -1;
	test[1] = 0;
	execute_commands(num_commands, arv, test, data);
	while (wait(&status) > 0)
		if (WIFEXITED(status))
			data->pipes->count = WEXITSTATUS(status);
	return (0);
}
