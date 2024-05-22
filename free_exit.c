/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:52:49 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/21 17:54:06 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_exit(t_vars *list, t_env_path *env_shell)
{
	t_vars	*tmp;
	t_vars	*tmp2;
	int		i;

	i = 0;
	while (env_shell->env_paths[i])
	{
		free(env_shell->env_paths[i]);
		i++;
	}
	free(env_shell->env_paths);
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->token);
		free(tmp);
	}
	exit(0);
}