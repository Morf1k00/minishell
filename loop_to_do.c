/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_to_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:51 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/22 18:03:24 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command(char **args, t_env_path *env_shell)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env_shell->env_paths) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int	status;
		waitpid(pid, &status, 0);
	}
}

void command_to_do(t_vars *list, t_env_path *env_shell)
{
	if (list->type == CMD)
	{
		if (ft_strncmp(list->token, "cd", 2) == 0)
			change_dir(env_shell, list);
		else if (ft_strncmp(list->token, "pwd", 3) == 0)
			ft_pwd(env_shell);
		else if (ft_strncmp(list->token, "echo", 4) == 0)
			echo(&list);
		else if (ft_strncmp(list->token, "export", 6) == 0)
			execute_export_command(env_shell->pipes->arv, env_shell);
		// else if (ft_strcmp(list->token, "unset") == 0)
		// 	unset_cmd(list->next, env_shell);
		else if (ft_strncmp(list->token, "env", 3) == 0)
			ft_env(env_shell);
		else
			execute_command(extract_cmd(list->token, env_shell->path), env_shell);
		// else
		// 	exec_cmd(list, env_shell);
	}
}