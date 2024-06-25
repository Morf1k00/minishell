/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:30:00 by debizhan          #+#    #+#             */
/*   Updated: 2024/06/25 18:36:20 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_command_segment(t_env_path *data, char **arv, int cmd_start, int prev_fd, int *pipe_fd);
static void	handle_pipes(int *pipe_fd, int cmd_index, int num_commands);
static void	close_pipes(int prev_fd, int *pipe_fd);
static int	wait_for_children(t_env_path *data);

int	execute_pipe(t_env_path *data, char **arv, int num_commands)
{
	int	pipe_fd[2];
	int	prev_fd;
	int	i;
	int	cmd_start;
	int	cmd_index;

	prev_fd = -1;
	cmd_start = 0;
	cmd_index = 0;
	i = 0;
	while (cmd_index < num_commands)
	{
		handle_pipes(pipe_fd, cmd_index, num_commands);
		while (arv[i] && strcmp(arv[i], "|") != 0)
			i++;
		arv[i] = NULL;
		execute_command_segment(data, arv, cmd_start, prev_fd, pipe_fd);
		close_pipes(prev_fd, pipe_fd);
		prev_fd = pipe_fd[0];
		cmd_start = ++i;
		cmd_index++;
	}
	return (wait_for_children(data));
}

static void	handle_pipes(int *pipe_fd, int cmd_index, int num_commands)
{
	if (cmd_index < num_commands - 1)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		pipe_fd[0] = -1;
		pipe_fd[1] = -1;
	}
}

static void	close_pipes(int prev_fd, int *pipe_fd)
{
	if (prev_fd != -1)
		close(prev_fd);
	if (pipe_fd[1] != -1)
		close(pipe_fd[1]);
}

static void	execute_command_segment(t_env_path *data, char **arv, int cmd_start, int prev_fd, int *pipe_fd)
{
	pid_t	pid;
	int		j;

	printf("Executing command:");
	j = cmd_start;
	while (arv[j] != NULL)
		printf(" %s", arv[j++]);
	printf("\n");
	if ((pid = fork()) == 0)
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
}

static int	wait_for_children(t_env_path *data)
{
	int	status;

	while (wait(&status) > 0)
	{
	}
	if (WIFEXITED(status))
		data->pipes->count = WEXITSTATUS(status);
	return (0);
}

// int	execute_pipe(t_env_path *data, char **arv, int num_commands)
// {
// 	int		pipe_fd[2];
// 	int		prev_fd;
// 	pid_t	pid;
// 	int		status;
// 	int		i;
// 	int		cmd_start;
// 	int		cmd_index;

// 	i = 0;
// 	prev_fd = -1;
// 	cmd_start = 0;
// 	cmd_index = 0;
// 	while (cmd_index < num_commands)
// 	{
// 		if (cmd_index < num_commands - 1)
// 		{
// 			if (pipe(pipe_fd) == -1)
// 			{
// 				perror("pipe");
// 				exit(EXIT_FAILURE);
// 			}
// 		}
// 		else
// 		{
// 			pipe_fd[0] = -1;
// 			pipe_fd[1] = -1;
// 		}
// 		// Find the end of the current command
// 		while (arv[i] && strcmp(arv[i], "|") != 0)
// 			i++;
// 		arv[i] = NULL;  // Null-terminate the current command
// 		// Debug output
// 		printf("Executing command:");
// 		for (int j = cmd_start; arv[j] != NULL; j++)
// 			printf("%s", arv[j]);
// 		printf("\n");
// 		if ((pid = fork()) == 0)
// 		{
// 			// Child process
// 			if (prev_fd != -1)
// 			{
// 				dup2(prev_fd, STDIN_FILENO);
// 				close(prev_fd);
// 			}
// 			if (pipe_fd[1] != -1)
// 			{
// 				dup2(pipe_fd[1], STDOUT_FILENO);
// 				close(pipe_fd[1]);
// 			}
// 			close(pipe_fd[0]);
// 			// Setup redirections
// 			setup_redirections(&arv[cmd_start]);
// 			// Execute the command
// 			execvp(arv[cmd_start], &arv[cmd_start]);
// 			perror("execvp");
// 			exit(127);
// 		}
// 		// Parent process
// 		if (prev_fd != -1)
// 			close(prev_fd);
// 		if (pipe_fd[1] != -1)
// 			close(pipe_fd[1]);
// 		prev_fd = pipe_fd[0];
// 		cmd_start = ++i;  // Move to the next command
// 		cmd_index++;
// 	}
// 	// Wait for all child processes to finish
// 	while (wait(&status) > 0);
// 	if (WIFEXITED(status))
// 		data->pipes->count = WEXITSTATUS(status);
// 	return (0);
// }
