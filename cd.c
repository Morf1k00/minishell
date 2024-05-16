/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:13:09 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/16 18:42:27 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parent_dir(char *list, t_env_path *env_shell)
{
	char *new_dir;
	char *curent_dir;

	curent_dir = get_pathd(env_shell->env_paths, 4, "PWD=");
	while (ft_strncmp(env_shell->*env_paths, "PWD=", 4))
		env_shell->env_paths++;
	curent_dir = env_shell->*env_paths;
	if (*list[0] == '/')
		new_dir = ft_strdup(list);
	else
	{
		strcpy(new_dir, curent_dir);
		strcat(new_dir, "/");
		strcat(new_dir, list);
	}
	if (chdir(new_dir) != 0)
	{
		ft_putchar_fd("bash: cd:", 1);
		ft_putchar_fd(list, 1);
		ft_putstr_fd("Not a directory", 1);
	}
	free(env_shell->*env_paths);
	env_shell->*env_paths = strdup(new_dir);
}

void change_dir(t_env_path *env_shell, t_vars **list)
{
	while (list->next)
	{
		if (list->type == SPACE_T)
			list = list->next;
		if (list->type == WORD)
			parent_dir(list, env_shell);
			
	}
}
