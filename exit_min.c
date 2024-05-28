/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:25:00 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/28 12:16:43 by rkrechun         ###   ########.fr       */
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

void	shell_lvl(t_env_path *env_shell)
{
	int		lvl;
	char	*cur_lvl;
	int		i;

	i = 0;
	cur_lvl = get_pathd(env_shell->env_paths, 6, "SHLVL=");
	while (ft_strncmp(env_shell->env_paths[i], "SHLVL=", 6))
		i++;
	lvl = ft_atoi(cur_lvl);
	lvl++;
	free(env_shell->env_paths[i]);
	env_shell->env_paths[i] = ft_strjoin("SHLVL=", ft_itoa(lvl));
}

void	exit_file(t_env_path *env_shell)
{
	char	*path;
	int		lvl;
	int		j;

	j = 0;
	path = get_pathd(env_shell->env_paths, 6, "SHLVL=");
	//printf("path = %s\n", path);
	if (ft_strncmp(path, "1", 1) == 0)
	{	
		exit(0);
		
	}
		//free_exit(list, env_shell); // function to exit and free all things
	else
	{
		lvl = ft_atoi(path);
		lvl--;
		while (ft_strncmp(env_shell->env_paths[j], "SHLVL=", 6))
			j++;
		free(env_shell->env_paths[j]);
		env_shell->env_paths[j] = ft_strjoin("SHLVL=", ft_itoa(lvl));
		//printf("env_paths = %s\n", env_shell->env_paths[j]);
	}
	//free(list);
}
