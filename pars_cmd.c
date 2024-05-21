/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:47:24 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/21 18:12:20 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	easy_check(t_vars *list)
{
	if (list->type == WORD)
	{
		if (ft_strncmp(list->token, "echo", 4) == 0)
			list->type = CMD;
		else if (ft_strncmp(list->token, "cd", 2) == 0)
			list->type = CMD;
		else if (ft_strncmp(list->token, "pwd", 3) == 0)
			list->type = CMD;
		else if (ft_strncmp(list->token, "export", 6) == 0)
			list->type = CMD;
		else if (ft_strncmp(list->token, "unset", 5) == 0)
			list->type = CMD;
		else if (ft_strncmp(list->token, "env", 3) == 0)
			list->type = CMD;
		else
			return (1);
	}
	return (0);
}

void	check_cmd(t_vars *list, t_env_path *env_shell)
{
	char	*path;
	char	*cmd;
	t_vars	*tmp;
	
	tmp = list;
	path = get_pathm(env_shell->env_paths);
	while (list->next)
	{
		if (list->type == WORD)
		{
			if (easy_check(list) == 0)
				continue ;
			else if (ft_strncmp(list->token, "exit", 4) == 0)
				exit_file(list, env_shell);
			else
			{
				cmd = ft_strjoin(path, "/");
				cmd = ft_strjoin(cmd, list->token);
				if (access(cmd, F_OK) == 0)
					list->type = CMD;
				free(cmd);
			}
		}
		if (list->next)
			list = list->next;
	}
	list = tmp;
}
