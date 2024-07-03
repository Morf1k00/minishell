/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:25:00 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/03 18:24:50 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_shell(t_env_path *env_shell)
{
	int	i;

	i = 0;
	while (ft_strncmp(env_shell->env_paths[i], "SHLVL=", 6))
		i++;
	env_shell->shelllvl = ft_strdup(env_shell->env_paths[i]);
	shell_lvl(env_shell);
}

void	shell_lvl(t_env_path *env_shell)
{
	int		lvl;
	char	*cur_lvl;
	int		i;
	char 	*tmp;

	i = 0;
	cur_lvl = get_pathd(env_shell->env_paths, 6, "SHLVL=");
	while (ft_strncmp(env_shell->env_paths[i], "SHLVL=", 6))
		i++;
	lvl = ft_atoi(cur_lvl);
	lvl++;
	free(env_shell->env_paths[i]);
	tmp = ft_itoa(lvl);
	env_shell->env_paths[i] = ft_strjoin("SHLVL=", tmp);
	free(tmp);
}

void free_array1(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	exit_file(t_vars *list, t_env_path *env_shell)
{
	char	*path;
	int		lvl;
	int		j;
	char 	*tmp;

	j = 0;
	while (ft_strncmp(env_shell->env_paths[j], "SHLVL=", 6))
		j++;
	path = ft_strdup(env_shell->env_paths[j]);
	lvl = ft_atoi(path + 6);
	lvl--;
	free(env_shell->env_paths[j]);
	tmp = ft_itoa(lvl);
	env_shell->env_paths[j] = ft_strjoin("SHLVL=", tmp);
	free(tmp);
	if (ft_strcmp(env_shell->env_paths[j], env_shell->shelllvl) == 0)
	{
		ft_listclear(&list);
			free_array1(env_shell->pipes->arv);
		free(env_shell->pipes);
		free(env_shell->shelllvl);
		// free(env_shell->pipes->heredoc);
		// free(env_shell->pipes->input);
		// free(env_shell->path);
		// free(env_shell->vars);
		free(list);
		free(env_shell);
		exit(0);
	}
}
