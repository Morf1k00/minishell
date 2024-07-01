/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:53:07 by debizhan          #+#    #+#             */
/*   Updated: 2024/07/01 15:42:40 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
	{
		return (malloc(new_size));
	}
	else if (new_size <= old_size)
	{
		return (ptr);
	}
	else
	{
		new_ptr = malloc(new_size);
		if (new_ptr)
		{
			ft_memcpy(new_ptr, ptr, old_size);
			free(ptr);
		}
		return (new_ptr);
	}
}

void	close_pipes(int prev_fd, int *pipe_fd)
{
	if (prev_fd != -1)
		close(prev_fd);
	if (pipe_fd[1] != -1)
		close(pipe_fd[1]);
}

void	create_pipe(int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}
