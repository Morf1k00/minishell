/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:14:11 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/03 16:00:56 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int change_line_with_pipes(t_env_path *env_shell)
{
	int i;
	char **tmp;

	i = 0;
	tmp = env_shell->pipes->arv;
	while (tmp[i] != NULL)
	{
		if (tmp[i][0] == '|' && tmp[i][1] == '|')
		{	
			tmp[i - 1] = NULL;
			while (tmp[i] != NULL)
			{
				tmp[i] = NULL;
				i++;
			}
			return(1);
		}
		if (tmp[i] != NULL)
			i++;
	}
	return(0);
}

void	check_pipe_line(t_env_path *env_shell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (change_line_with_pipes(env_shell) == 1)
		env_shell->pipes->pipe_i = 0;
	else
	{
		while (env_shell->pipes->arv[i] != NULL)
		{
			if (env_shell->pipes->arv[i][0] == '|'
				&& env_shell->pipes->arv[i][1] == '\0')
				j++;
			i++;
			env_shell->pipes->pipe_i = j;
		}
	}
}