/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:55:40 by debizhan          #+#    #+#             */
/*   Updated: 2024/06/18 15:01:24 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	redirect_output(char *filename, int append)
// {
// 	int	fd;

// 	if (append)
// 		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
// 	else
// 		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (dup2(fd, STDOUT_FILENO) < 0)
// 	{
// 		perror("dup2");
// 		exit(EXIT_FAILURE);
// 	}
// 	close (fd);
// }

// void	redirect_input(char *filename)
// {
// 	int	fd;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (dup2(fd, STDIN_FILENO) < 0)
// 	{
// 		perror("dup2");
// 		exit(EXIT_FAILURE);
// 	}
// 	close(fd);
// }

// void check_redirection(t_env_path *env_shell)
// {
	
// }

// void	setup_redirections(t_env_path *env_shell)
// {
// 	t_vars	*lis;

// 	lis = env_shell->list;
	
// 	while (lis)
// 	{
// 		if (lis->type == GREATER_THEN)
// 		{
// 			redirect_output(lis->next->token, 0);
// 		}
// 		else if (lis->type == APPEND)
// 		{
// 			redirect_output(lis->next->token, 1);
// 		}
// 		else if (lis->type == LESS_THEN)
// 		{
// 			redirect_input(lis->next->token);
// 		}
// 		lis = lis->next;
// 	}
	
// }
