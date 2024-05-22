/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_to_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:51 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/22 14:13:50 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void command_to_do(t_vars *list, t_env_path *env_shell)
{
	if (list->type == CMD)
		{
			if (ft_strncmp(list->token, "cd", 2) == 0)
				change_dir(env_shell, list);
			// else if (ft_strcmp(list->token, "cd") == 0)
			// 	parent_dir(list->next->token, env_shell);
			else if (ft_strncmp(list->token, "pwd", 3) == 0)
				ft_pwd(env_shell);
			// else if (ft_strcmp(list->token, "export") == 0)
			// 	export_cmd(list->next, env_shell);
			// else if (ft_strcmp(list->token, "unset") == 0)
			// 	unset_cmd(list->next, env_shell);
			else if (ft_strncmp(list->token, "env", 3) == 0)
				ft_env(env_shell);
			// else
			// 	exec_cmd(list, env_shell);
		}
	
}