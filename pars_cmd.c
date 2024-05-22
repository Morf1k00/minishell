/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:47:24 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/22 16:17:12 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	easy_check(t_vars *list)
{
	if (ft_strncmp(list->token, "echo", 4) == 0)
		return (0);
	else if (ft_strncmp(list->token, "cd", 2) == 0)
		return (0);
	else if (ft_strncmp(list->token, "pwd", 3) == 0)
		return (0);
	else if (ft_strncmp(list->token, "export", 6) == 0)
		return (0);
	else if (ft_strncmp(list->token, "unset", 5) == 0)
		return (0);
	else if (ft_strncmp(list->token, "env", 3) == 0)
		return (0);
	else
		return (1);
}

void	check_cmd(t_vars *list, t_env_path *env_shell)
{
	char	*path;
	char	*cmd;
	char 	*tmp;

	if (easy_check(list) == 0)
		list->type = CMD;
	else if (ft_strncmp(list->token, "exit", 4) == 0)
		exit_file(list, env_shell);
	else
	{
		path = get_pathm(env_shell->env_paths);
		//printf("path = %s\n", path);
		tmp = ft_strjoin(path, "/");
		cmd = ft_strjoin(tmp, list->token);
		//printf("cmd = %s\n", cmd);
		if (access(cmd, F_OK) == 0)
			list->type = CMD;
		free(cmd);
	}
}
