/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:14:11 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/28 16:28:03 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_pipe_line(t_env_path *env_shell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env_shell->pipes->arv[i] != NULL)
	{
		if (env_shell->pipes->arv[i][0] == '|'
			&& env_shell->pipes->arv[i][1] == '\0')
		{
			j++;
			env_shell->pipes->pipe_i = j;
		}
		i++;
	}
}
