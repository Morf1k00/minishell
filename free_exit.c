/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:52:49 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/02 14:07:30 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	free_exit(t_vars *list, t_env_path *env_shell)
// {
// 	int		i;

// 	i = 0;
// 	while (env_shell->env_paths[i] != NULL)
// 	{
// 		free(env_shell->env_paths[i]);
// 		i++;
// 	}
// 	//free(env_shell->env_paths);
// 	ft_listclear(&list);
// }


// void free_struct(t_env_path *env_shell)
// {
// 	int		i;

// 	i = 0;
// 	while (env_shell->env_paths[i] != NULL)
// 	{
// 		free(env_shell->env_paths[i]);
// 		i++;
// 	}
// 	// free(env_shell->pipes->arv[i]);
// 	free(env_shell);
// }