/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:13:09 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/22 17:53:17 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*chdir0(char *new_dir, char *current_dir, char *list)
{
	ft_putstr_fd("minishell: cd: ", 1);
	ft_putstr_fd(list, 1);
	ft_putstr_fd(": No such file or directory\n", 1);
	free(new_dir);
	new_dir = ft_strdup(current_dir);
	return (new_dir);
}

static void	child_dir(char *list, t_env_path *env_shell)
{
	char	*new_dir;
	char	*curent_dir;
	int		i;
	char	*pwd;

	i = 0;
	curent_dir = get_pathd(env_shell->env_paths, 4, "PWD=");
	while (ft_strncmp(env_shell->env_paths[i], "PWD=", 4))
		i++;
	if (list[0] == '/')
		new_dir = ft_strdup(list);
	else
	{
		new_dir = ft_strdup(curent_dir);
		if (new_dir[ft_strlen(curent_dir) - 1] != '/')
			new_dir = ft_strjoin(new_dir, "/");
		if (list[ft_strlen(list) - 1] == '/')
			list[ft_strlen(list) - 1] = '\0';
		new_dir = ft_strjoin(new_dir, list);
	}
	if (chdir(new_dir) != 0)
		new_dir = chdir0(new_dir, curent_dir, list);
	free(env_shell->env_paths[i]);
	pwd = ft_strjoin("PWD=", new_dir);
	env_shell->env_paths[i] = strdup(pwd);
}

static void	parent_dir(char *list, t_env_path *env_shell)
{
	char	*new_dir;
	char	*current_dir;
	int		i;
	int		j;
	char	*pwd;

	j = 0;
	current_dir = get_pathd(env_shell->env_paths, 4, "PWD=");
	while (ft_strncmp(env_shell->env_paths[j], "PWD=", 4))
		j++;
	i = lenpath(current_dir) - lencat(current_dir, lenpath(current_dir));
	new_dir = (char *)malloc(sizeof(char) * (i + 1));
	strncpy(new_dir, current_dir, i);
	new_dir[i] = '\0';
	if (list[2] == '/')
		new_dir = ft_strjoin(new_dir, list + 2);
	if (new_dir[0] == '\0')
		new_dir = ft_strdup("/");
	if (list[ft_strlen(list) - 1] == '/')
		new_dir[ft_strlen(new_dir) - 1] = '\0';
	if (chdir(new_dir) != 0)
		new_dir = chdir0(new_dir, current_dir, list);
	free(env_shell->env_paths[j]);
	pwd = ft_strjoin("PWD=", new_dir);
	env_shell->env_paths[j] = strdup(pwd);
}

void	change_dir(t_env_path *env_shell, t_vars *list)
{
	t_vars	*tmp;
	
	tmp = list;
	if (tmp->next)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
			if (tmp->type == SPACE_T)
				tmp = tmp->next;
			if (tmp->type == CMD)
			{
				if (tmp->token[0] == '.' && tmp->token[1] == '.' )
					parent_dir(tmp->token, env_shell);
				else
					child_dir(tmp->token, env_shell);
				if (tmp->type != WORD && tmp->type != SPACE_T)
					break ;
			}
		}
	}
}
