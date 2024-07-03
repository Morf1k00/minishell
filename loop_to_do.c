/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_to_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:49:10 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/03 16:37:54 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_command_external(char **args, char **line,
	t_env_path *env_shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		env_shell->last_exit_status = 1;
	}
	else if (pid == 0)
	{
		if (execve(args[0], line, env_shell->env_paths) == -1)
			ft_error_exit("execve");
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			env_shell->last_exit_status = WEXITSTATUS(status);
		else
			env_shell->last_exit_status = 1;
	}
}

void	exe_loop(t_vars *list, char **line, int i)
{
	while (list && list->type != PIPE)
	{
		if (list->type == SPACE_T)
		{
			list = list->next;
			continue ;
		}
		if (list->type == GREATER_THEN
			|| list->type == LESS_THEN || list->type == APPEND)
		{
			list = list->next;
			break ;
		}
		line[i] = ft_strdup(list->token);
		list = list->next;
		i++;
	}
	line[i] = NULL;
}

void free_array(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	execute_comand(char **args, t_vars *list, t_env_path *env_shell)
{
	char	**line;
	t_vars	*tmp;
	int		i;

	i = 1;
	tmp = list;
	tmp = tmp->next;
	while (tmp && tmp->type != PIPE)
	{
		tmp = tmp->next;
		i++;
	}
	line = malloc(sizeof(char *) * (i + 1));
	line[0] = ft_strdup(list->token);
	i = 1;
	list = list->next;
	exe_loop(list, line, i);
	execute_command_external(args, line, env_shell);
	// free(line);// last changes 60 byte
	free_array(args);//its work
	free_array(line);// its work
}

void	command_to_do(t_vars *list, t_env_path *env_shell)
{
	while (list)
	{
		if (list->type == CMD)
		{
			if (ft_strcmp(list->token, "cd") == 0)
				change_dir(env_shell, list);
			else if (ft_strcmp(list->token, "pwd") == 0)
				ft_pwd(env_shell);
			else if (ft_strcmp(list->token, "echo") == 0)
				echo(&list);
			else if (ft_strcmp(list->token, "export") == 0)
				execute_export_command(env_shell->pipes->arv, env_shell);
			else if (ft_strcmp(list->token, "unset") == 0)
				execute_unset_command(env_shell->pipes->arv, env_shell);
			else if (ft_strcmp(list->token, "exit") == 0)
				ft_env(env_shell);
			else
				execute_comand(extract_cmd(list->token, env_shell->path), list,
					env_shell);
		}
		else if (list->type == INVALID)
			printf("%s: command not found\n", list->token);
		list = list->next;
	}
}
