/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:25:00 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/28 17:16:16 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	exit_file(t_vars *list, t_env_path *env_shell)
{
	char	*path;
	int		lvl;
	int		j;

	j = 0;
	path = get_pathd(env_shell->env_paths, 6, "SHLVL=");
	if (ft_strncmp(path, "1", 1) == 0)
	{
		// free_exit(list, env_shell);
		free(list);
		exit(0);
	}
	else
	{
		lvl = ft_atoi(path);
		lvl--;
		while (ft_strncmp(env_shell->env_paths[j], "SHLVL=", 6))
			j++;
		free(env_shell->env_paths[j]);
		env_shell->env_paths[j] = ft_strjoin("SHLVL=", ft_itoa(lvl));
	}
}
