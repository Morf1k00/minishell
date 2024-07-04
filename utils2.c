/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:53:07 by debizhan          #+#    #+#             */
/*   Updated: 2024/07/04 15:07:34 by rkrechun         ###   ########.fr       */
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

void	set_type(t_vars *list, t_env_path *env_shell)
{
	int	i;

	i = 0;
	while (list)
	{
		if (i == 0)
			check_cmd(list, env_shell);
		if (list->type == PIPE || list->type == GREATER_THEN
			|| list->type == LESS_THEN || list->type == APPEND)
		{
			list = list->next;
			i = 0;
		}
		else
		{
			list = list->next;
			i++;
		}
	}
}

void cleanup(t_env_path *env_shell, t_vars *list)
{
    int i;
    i = 0;    
	if (env_shell)
    {        
		if (env_shell->env_paths)
        {            
			while (env_shell->env_paths[i])
                free(env_shell->env_paths[i++]);            
			free(env_shell->env_paths);
        }        
		if (env_shell->pipes)
            free(env_shell->pipes);        
		free(env_shell);
    }   ft_listclear(&list);
}
