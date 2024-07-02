/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_to_do.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:49:10 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/02 16:02:39 by rkrechun         ###   ########.fr       */
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
	}
	else if (pid == 0)
	{
		if (execve(args[0], line, env_shell->env_paths) == -1)
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

static void	help_function(char **line, t_vars *list, int i)
{
	line[0] = list->token;
	i = 1;
	list = list->next;
	while (list && list->type != PIPE)
	{
		if (list->type == SPACE_T)
		{
			list = list->next;
			continue ;
		}
		if (list->type == GREATER_THEN || list->type == LESS_THEN
			|| list->type == APPEND)
		{
			list = list->next;
			break ;
		}
		line[i] = list->token;
		list = list->next;
		i++;
	}
	line[i] = NULL;
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
	help_function(line, list, i);
	execute_command_external(args, line, env_shell);
	free(line);
}

void	command_to_do(t_vars *list, t_env_path *env_shell)
{
	while (list)
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
			else if (ft_strncmp(list->token, "exit", 4) == 0)
				exit_file(list, env_shell);
			else
				execute_comand(extract_cmd(list->token, env_shell->path), list,
					env_shell);
		}
		list = list->next;
	}
}
