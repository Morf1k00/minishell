/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:29:34 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/03 16:51:58 by rkrechun         ###   ########.fr       */
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

static void	nullargs(char **args, int i)
{
	args[i] = NULL;
	args[i + 1] = NULL;
}

void	setup_redirections(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strcmp(args[i], ">") == 0)
		{
			redirect_output(args[i + 1], 0);
			nullargs(args, i);
			break ;
		}
		else if (ft_strcmp(args[i], ">>") == 0)
		{
			redirect_output(args[i + 1], 1);
			nullargs(args, i);
			break ;
		}
		else if (ft_strcmp(args[i], "<") == 0)
		{
			redirect_input(args[i + 1]);
			nullargs(args, i);
			break ;
		}
		i++;
	}
}
