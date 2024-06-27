/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:55:14 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/27 16:30:56 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin_command(char *command)
{
	return (strcmp(command, "cd") == 0 );
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

void check_heredoc(t_env_path *env_shell)
{
	// char **tmp;
	int i;
	
	i = 0;
	// tmp = env_shell->pipes->arv;
	while (env_shell->pipes->arv[i])
	{
		if (strcmp(env_shell->pipes->arv[i], "<<") == 0)
		{	
			heredoc_min(env_shell->pipes->arv [i + 2]);
			printf("heredoc\n");
			env_shell->pipes->arv[i] = ".here_doc";
			env_shell->pipes->arv[i + 2] = " ";
			break;
		}
		i++;
	}
		// for (int j = 0; env_shell->pipes->arv[j]; j++)
		// 	printf("arv[%d]: %s\n", j, env_shell->pipes->arv[j]);
	//env_shell->pipes->arv = tmp;
	return;
}

void	execom(t_vars *list, t_env_path *env_shell)
{
	pid_t	pid;
	int    status;

	// check_heredoc(env_shell);
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
