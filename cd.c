/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:13:09 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/21 17:26:40 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_dir(char *list, t_env_path *env_shell)
{
	char	*new_dir;
	char	*curent_dir;
	int i;

	i = 0;
	curent_dir = get_pathd(env_shell->env_paths, 4, "PWD=");
	while (ft_strncmp(env_shell->env_paths[i], "PWD=", 4))
		i++;
	curent_dir = env_shell->env_paths[i];
	if (list[0] == '/')
		new_dir = ft_strdup(list);
	else
	{
		new_dir = ft_strdup(curent_dir);
		ft_strjoin(new_dir, "/");
		ft_strjoin(new_dir, list);
	}
	if (chdir(new_dir) != 0)
	{
		ft_putstr_fd("bash: cd:", 1);
		ft_putstr_fd(list, 1);
		ft_putstr_fd("Not a directory", 1);
		free(new_dir);
		new_dir = ft_strdup(curent_dir);
	}
	free(env_shell->env_paths[i]);
	env_shell->env_paths[i] = strdup(new_dir);
}

static void	parent_dir(char *list, t_env_path *env_shell)
{
	char	*new_dir;
	char	*current_dir;
	int		i;
	int		ct;
	int		j;

	j = 0;
	current_dir = get_pathd(env_shell->env_paths, 4, "PWD=");
	while (ft_strncmp(env_shell->env_paths[j], "PWD=", 4))
		j++;
	current_dir = env_shell->env_paths[j];
	i = lenpath(current_dir);
	ct = lencat(current_dir, i);
	new_dir = (char *)malloc(sizeof(char) * (i - ct + 1));
	strncpy(new_dir, current_dir, i - ct);
	if (chdir(new_dir) != 0)
	{
		ft_putstr_fd("bash: cd:", 1);
		ft_putstr_fd(list, 1);
		ft_putstr_fd("Not a directory", 1);
		free(new_dir);
		new_dir = ft_strdup(current_dir);
	}
	free(env_shell->env_paths[j]);
	env_shell->env_paths[j] = strdup(new_dir);
}

void	change_dir(t_env_path *env_shell, t_vars *list)
{
	if (list->next)
	{
		while (list->next)
		{
			list = list->next;
			if (list->type == SPACE_T)
				list = list->next;
			if (list->type == WORD)
			{
				if (list->token[0] == '.' && list->token[1] == '.' )
					parent_dir(list->token, env_shell);
				else
					child_dir(list->token, env_shell);
				if (list->type != WORD && list->type != SPACE_T)
					break ;
			}
		}
	}
}
