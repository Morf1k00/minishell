/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:55:40 by debizhan          #+#    #+#             */
/*   Updated: 2024/06/27 16:30:05 by debizhan         ###   ########.fr       */
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
		ft_error_exit("open");
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("dup2");
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

void	redirect_input(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error_exit("open");
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("dup2");
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

static void	loop(char **args, int i)
{
	while (args[i])
	{
		if (strcmp(args[i], ">") == 0)
		{
			redirect_output(args[i + 1], 0);
			args[i] = NULL;
			args[i + 1] = NULL;
			break ;
		}
		else if (strcmp(args[i], ">>") == 0)
		{
			redirect_output(args[i + 1], 1);
			args[i] = NULL;
			args[i + 1] = NULL;
			break ;
		}
		else if (strcmp(args[i], "<") == 0)
		{
			redirect_input(args[i + 1]);
			args[i] = NULL;
			args[i + 1] = NULL;
			break ;
		}
		i++;
	}
}

void	setup_redirections(char **args)
{
	int	i;

	i = 0;
	loop(args, i);
}
