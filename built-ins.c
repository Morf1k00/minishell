/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:06:40 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/28 16:16:43 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin_command(char *command)
{
	return (strcmp(command, "cd") == 0 || strcmp(command, "echo") == 0
		|| strcmp(command, "export") == 0 || strcmp(command, "unset") == 0
		|| strcmp(command, "pwd") == 0 || strcmp(command, "env") == 0);
}

void	handle_builtin_command(t_vars *list, t_env_path *env_shell)
{
	if (strcmp(list->token, "cd") == 0)
		change_dir(env_shell, list);
	else if (strcmp(list->token, "echo") == 0)
		echo(&list);
	else if (strcmp(list->token, "export") == 0)
		execute_export_command(env_shell->pipes->arv, env_shell);
	else if (strcmp(list->token, "unset") == 0)
		execute_unset_command(env_shell->pipes->arv, env_shell);
	else if (strcmp(list->token, "pwd") == 0)
		ft_pwd(env_shell);
	else if (strcmp(list->token, "env") == 0)
		ft_env(env_shell);
}

void	execute_command(t_vars *list, t_env_path *env_shell)
{
	pid_t	pid;
	int		status;

	if (is_builtin_command(list->token))
		handle_builtin_command(list, env_shell);
	else
	{
		pid = fork();
		if (pid < 0)
			perror("fork");
		else if (pid == 0)
		{
			setup_redirections(env_shell->pipes->arv);
			command_to_do(list, env_shell);
			exit(EXIT_SUCCESS);
		}
		else
			waitpid(pid, &status, 0);
	}
}
