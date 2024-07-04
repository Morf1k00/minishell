/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:52:49 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/04 14:34:31 by debizhan         ###   ########.fr       */
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
// 	ft_listclear(&list);
// }}

// static void free_split_array(char **array) {
//     int i = 0;
//     while (array[i]) {
//         free(array[i]);
//         i++;
//     }
//     free(array);
// }

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
		{
			if (env_shell->pipes->output)
				free(env_shell->pipes->output);
			free(env_shell->pipes);
		}
		free(env_shell);
	}
	ft_listclear(&list);
}
