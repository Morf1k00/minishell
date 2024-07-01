/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:35:37 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/01 13:12:15 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipes(int prev_fd, int *pipe_fd)
{
	if (prev_fd != -1)
		close(prev_fd);
	if (pipe_fd[1] != -1)
		close(pipe_fd[1]);
}

void	handle_child_process(int prev_fd, int *pipe_fd,
				char **arv, int cmd_start)
{
	if (prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	if (pipe_fd[1] != -1)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	close(pipe_fd[0]);
	setup_redirections(&arv[cmd_start]);
	execvp(arv[cmd_start], &arv[cmd_start]);
	perror("execvp");
	exit(127);
}

void	create_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	execute_commands(int num_commands, char **arv,
					int *prev_fd, int *cmd_start)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		i;
	int		cmd_index;

	i = 0;
	cmd_index = 0;
	while (cmd_index < num_commands)
	{
		if (cmd_index < num_commands - 1)
			create_pipe(pipe_fd);
		else
		{
			pipe_fd[0] = -1;
			pipe_fd[1] = -1;
		}
		while (arv[i] && strcmp(arv[i], "|") != 0)
			i++;
		arv[i] = NULL;
		pid = fork();
		if (pid == 0)
			handle_child_process(*prev_fd, pipe_fd, arv, *cmd_start);
		close_pipes(*prev_fd, pipe_fd);
		*prev_fd = pipe_fd[0];
		*cmd_start = ++i;
		cmd_index++;
	}
}

int	execute_pipe(t_env_path *data, char **arv, int num_commands)
{
	int	prev_fd;
	int	cmd_start;
	int	status;

	prev_fd = -1;
	cmd_start = 0;
	execute_commands(num_commands, arv, &prev_fd, &cmd_start);
	while (wait(&status) > 0)
		if (WIFEXITED(status))
			data->pipes->count = WEXITSTATUS(status);
	return (0);
}
