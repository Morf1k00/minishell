/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:47:24 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/04 13:30:27 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	easy_check(t_vars *list)
{
	if (ft_strcmp(list->token, "echo") == 0)
		return (0);
	else if (ft_strcmp(list->token, "cd") == 0)
		return (0);
	else if (ft_strcmp(list->token, "pwd") == 0)
		return (0);
	else if (ft_strcmp(list->token, "export") == 0)
		return (0);
	else if (ft_strcmp(list->token, "unset") == 0)
		return (0);
	else if (ft_strcmp(list->token, "env") == 0)
		return (0);
	else if (ft_strcmp(list->token, "./minishell") == 0)
		return (0);
	else
		return (-1);
}

void	kostil(t_env_path *env_shell, t_vars *list)
{
	char	**cmd;
	char	*path;

	path = env_shell->path;
	cmd = extract_cmd(list->token, path);
	if (access(cmd[0], F_OK) == 0)
		list->type = CMD;
	else
	{
		list->type = INVALID;
		env_shell->last_exit_status = 127;
	}
	free_array(cmd);
}

void	check_cmd(t_vars *list, t_env_path *env_shell)
{
	if (easy_check(list) == 0)
		list->type = CMD;
	else if (ft_strncmp(list->token, "exit", 4) == 0)
		exit_file(list, env_shell);
	else if (list->token[0] == '.' && list->token[1] == '.')
		list->type = WORD;
	else if (list->token[0] == '\'')
		list->type = SINGLE_QUOTES;
	else if (list->token[0] == '\"')
		list->type = DOUBLE_QUOTES;
	else if (list->token[0] == ' ')
		list->type = SPACE_T;
	else
		kostil(env_shell, list);
}
