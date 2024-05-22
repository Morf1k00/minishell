/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/22 16:11:52 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_arg(int argc, char **argv, char **env, t_env_path *env_shell)
{
	(void)argc;
	(void)argv;
	init_path(env, env_shell);
}

// void	print_list(t_vars **lst)
// {
// 	t_vars	*tmp;

// 	tmp = *lst;
// 	while (tmp)
// 	{
// 		printf("info: %s\ttype: %d\tlength: %d\n", tmp->token, tmp->type, tmp->length);
// 		tmp = tmp->next;
// 	}
// }

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

int	main(int argc, char **argv, char **env)
{
	char		*input;
	char		**line;
	t_env_path	env_shell;
	t_vars		*list;

	list = NULL;
	init_arg(argc, argv, env, &env_shell);
	while (1)
	{
		input = readline("minishel: ");
		if (!input)
			break ;
		add_history(input);
		line = split_arg(input);
		if (line[0] == NULL)
			continue ;
		else if (strcmp(line[0], "exit") == 0)
			exit(EXIT_SUCCESS);
		else if (strcmp(line[0], "export") == 0)
			execute_export_command(line, &env_shell);
		else
		{
			if (close_quote(line))
				lexer(line, &env_shell);
			else
				write(STDOUT_FILENO, "quote not close\n", strlen("quote not close\n"));
			if (!create_list(&list, env_shell.pipes->arv))
			{
				write(STDOUT_FILENO, "smth went wrong\n", strlen("smth went wrong\n"));
				exit(EXIT_FAILURE);
			}
			while (list)
			{
				if (strcmp(list->token, "echo") == 0)
					echo(&list);
				else if (strcmp(list->token, "env") == 0)
					ft_env(&env_shell);
				if (list->next)
					list = list->next;
				else
					break ;
			}
			ft_listclear(&list);
		}
		// free(input);
	}
	return (0);
}
