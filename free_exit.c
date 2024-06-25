/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:52:49 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/25 14:31:59 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_exit(t_vars *list, t_env_path *env_shell)
{
	int		i;

	i = 0;
	while (env_shell->env_paths[i] != NULL)
	{
		free(env_shell->env_paths[i]);
		i++;
	}
	ft_listclear(&list);
}
