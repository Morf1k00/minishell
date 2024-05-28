/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_to_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:57:51 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/28 16:21:46 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command_external(char **args, t_env_path *env_shell)
{
	pid_t	pid;
	int		status;

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
		waitpid(pid, &status, 0);
	}
}

void	command_to_do(t_vars *list, t_env_path *env_shell)
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
		else if (ft_strncmp(list->token, "unset", 5) == 0)
			execute_unset_command(env_shell->pipes->arv, env_shell);
		else if (ft_strncmp(list->token, "./minishell", 11) == 0)
			shell_lvl(env_shell);
		else if (ft_strncmp(list->token, "env", 3) == 0)
			ft_env(env_shell);
		else
			execute_command_external(extract_cmd(list->token, env_shell->path),
				env_shell);
	}
}
