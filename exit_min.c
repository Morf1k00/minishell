/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:25:00 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/04 20:14:13 by debizhan         ###   ########.fr       */
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
	char	*tmp;

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

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	exit_file(t_vars *list, t_env_path *env_shell)
{
	char	*path;
	int		lvl;
	int		j;
	char	*tmp;

	j = 0;
	while (ft_strncmp(env_shell->env_paths[j], "SHLVL=", 6))
		j++;
	path = ft_strdup(env_shell->env_paths[j]);
	lvl = ft_atoi(path + 6);
	lvl--;
	free(env_shell->env_paths[j]);
	tmp = ft_itoa(lvl);
	env_shell->env_paths[j] = ft_strjoin("SHLVL=", tmp);
	if (ft_strcmp(env_shell->env_paths[j], env_shell->shelllvl) == 0)
	{
		free(tmp);
		free(path);
		ft_listclear(&list);
		free_array(env_shell->pipes->arv);
		free_array(env_shell->env_paths);
		free(env_shell->pipes);
		free(env_shell->shelllvl);
		free(list);
		free(env_shell);
		exit(0);
	}
}
