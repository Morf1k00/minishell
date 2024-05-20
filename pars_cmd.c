/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:47:24 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/20 13:45:04 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	easy_check(t_vars *list)
{
	if (list->type == WORD)
	{
		if (strcmp(list->token, "echo") == 0)
			list->type = CMD;
		else if (strcmp(list->token, "cd") == 0)
			list->type = CMD;
		else if (strcmp(list->token, "pwd") == 0)
			list->type = CMD;
		else if (strcmp(list->token, "export") == 0)
			list->type = CMD;
		else if (strcmp(list->token, "unset") == 0)
			list->type = CMD;
		else if (strcmp(list->token, "env") == 0)
			list->type = CMD;
		else
			return (1);
	}
	return (0);
}

void	check_cmd(t_vars **list, t_env_path *env_shell)
{
	char	*path;
	char	*cmd;

	path = get_pathm(env_shell->env_paths);
	while (*list->next)
	{
		if (*list->type == WORD)
		{
			if (easy_check(list) == 0)
				continue ;
			else
			{
				cmd = ft_strjoin(path, "/");
				cmd = ft_strjoin(cmd, *list->token);
				if (access(cmd, F_OK) == 0)
					*list->type = CMD;
				free(cmd);
			}
		}
		if (list->next)
			list = list->next;
	}
}
