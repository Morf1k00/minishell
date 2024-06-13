/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:06:40 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/30 16:14:18 by rkrechun         ###   ########.fr       */
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

static void	print_list(t_vars **lst)
{
	t_vars	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("info: %s\ttype: %d\tlength: %d\n", tmp->token, tmp->type, tmp->length);
		tmp = tmp->next;
	}
}

int number_cmd(t_vars *list)
{
	int i;
	t_vars *tmp;

	i = 0;
	tmp = list;
	while (tmp->next != NULL)
	{
		if (tmp->type == CMD || tmp->type == APPEND
		|| tmp->type == GREATER_THEN || tmp->type == LESS_THEN
		|| tmp->type == HEREDOC)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	execute_command(t_vars *list, t_env_path *env_shell)
{
	// pid_t	pid;
	// int		status;
	int i;

	i = 0;
	print_list(&list);
	i = number_cmd(list);
	printf("number of commands: %d\n", i);
	
	while (list)
	{
		
		if (is_builtin_command(list->token))
			handle_builtin_command(list, env_shell);
		else
		{
			// pid = fork();
			// if (pid < 0)
				// perror("fork");
			// else if (pid == 0)
			// {
				printf("executing command\n");
				//setup_redirections(env_shell->pipes->arv);
				command_to_do(list, env_shell);
				exit(EXIT_SUCCESS);
			// }
			// else
				// waitpid(pid, &status, 0);
		}
		list = list->next;
	}
}
