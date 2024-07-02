/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:55:14 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/02 15:56:11 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin_command(char *command)
{
	return (strcmp(command, "cd") == 0);
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

void	check_heredoc(t_env_path *env_shell)
{
	int	i;

	i = 0;
	while (env_shell->pipes->arv[i])
	{
		if (strcmp(env_shell->pipes->arv[i], "<<") == 0)
		{
			heredoc_min(env_shell->pipes->arv [i + 2]);
			env_shell->pipes->arv[i] = ".here_doc";
			env_shell->pipes->arv[i + 2] = " ";
			break ;
		}
		i++;
	}
	return ;
}

void	execom(t_vars *list, t_env_path *env_shell)
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
