/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:25:00 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/21 18:06:35 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	exit_utils(char *path)
// {
// 	char	*shl;
// 	int		i;
// 	char	*new_path;

// 	new_path = ft_strdup(ft_strrchr(path, '=') + 5);
// 	shl = ft_strchr(path, '=');
// 	shl++;
// 	i = ft_atoi(shl);
// 	i--;
// 	strcat(new_path, "=");
// 	strcat(new_path, ft_itoa(i));
// }

void	exit_file(t_vars *list, t_env_path *env_shell)
{
	char	*path;
	// char	*new_path;
	// int		j;

	// j = 0;
	path = get_pathd(env_shell->env_paths, 6, "SHLVL=");
	if (ft_strncmp(path, "SHLVL=1", 7) == 0)
		exit(0);//free_exit(list, env_shell); // function to exit and free all things
	// else
	// {
	// 	exit_utils(path);
	// 	while (env_shell->env_paths[j] != NULL && ft_strncmp(env_shell->env_paths[j], "SHLVL=", 6))
	// 		j++;
	// 	if (env_shell->env_paths[j] != NULL)
	// 	{
			
	// 		env_shell->env_paths[j] = ft_strdup(new_path);
	// 	}
	// 	free(new_path);
	// }
	free(list);
}
