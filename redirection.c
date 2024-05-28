/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:55:40 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/28 15:16:33 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_output(char *filename, int append)
{
	int	fd;

	if (append)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
}

void	redirect_input(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	setup_redirections(char **args)
{
	int	i;

	i = 0;
	while (args[i]) {
		if (strcmp(args[i], ">") == 0)
		{
			redirect_output(args[i + 2], 0);
			args[i] = NULL;
			break ;
		} else if (strcmp(args[i], ">>") == 0)
		{
			redirect_output(args[i + 2], 1);
			args[i] = NULL;
			break ;
		} else if (strcmp(args[i], "<") == 0)
		{
			redirect_input(args[i + 2]);
			args[i] = NULL;
			break ;
		}
		i++;
	}
}

void	execute_with_redirection(t_vars *list, t_env_path *env_shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		perror("fork");
	else if (pid == 0)
	{
		setup_redirections(env_shell->pipes->arv);
		command_to_do(list, env_shell);
		exit(EXIT_SUCCESS);
	} else
		waitpid(pid, &status, 0);
}
