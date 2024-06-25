/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:55:40 by debizhan          #+#    #+#             */
/*   Updated: 2024/06/19 18:27:38 by debizhan         ###   ########.fr       */
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
	if (fd < 0)
	{
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
	while (args[i])
	{
		// printf("args[%d]: %s\n", i, args[i]);
		if (strcmp(args[i], ">") == 0)
		{
			printf("args[%d]: %s\n", i, args[i]);
			redirect_output(args[i + 1], 0);
			args[i] = NULL;
			break ;
		}
		else if (strcmp(args[i], ">>") == 0)
		{
			printf("args[%d]: %s\n", i, args[i]);
			redirect_output(args[i + 1], 1);
			args[i] = NULL;
			break ;
		}
		else if (strcmp(args[i], "<") == 0)
		{
			printf("args[%d]: %s\n", i, args[i]);
			redirect_input(args[i + 1]);
			args[i] = NULL;
			break ;
		}
		i++;
	}
}
