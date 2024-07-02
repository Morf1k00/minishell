/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:12:28 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/27 16:32:37 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_pipe(t_env_path *data, char **arv, int num_commands)
{
	int		pipe_fd[2];
	int		prev_fd;
	pid_t	pid;
	int		status;
	int		i;
	int		cmd_start;
	int		cmd_index;

	i = 0;
	prev_fd = -1;
	cmd_start = 0;
	cmd_index = 0;
	while (cmd_index < num_commands)
	{
		if (cmd_index < num_commands - 1)
		{
			if (pipe(pipe_fd) == -1)
				ft_error_exit("pipe");
		}
		else
		{
			pipe_fd[0] = -1;
			pipe_fd[1] = -1;
		}
		while (arv[i] && strcmp(arv[i], "|") != 0)
			i++;
		arv[i] = NULL;
		if (!(pid = fork()))
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
		// Parent process
		if (prev_fd != -1)
			close(prev_fd);
		if (pipe_fd[1] != -1)
			close(pipe_fd[1]);
		prev_fd = pipe_fd[0];
		cmd_start = ++i;
		cmd_index++;
	}
	while (wait(&status) > 0);
	if (WIFEXITED(status))
		data->pipes->count = WEXITSTATUS(status);
	return (0);
}
