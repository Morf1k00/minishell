/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/14 16:43:31 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_arg(int argc, char **argv, char **env, t_env_path *env_shell)
{
	(void)argc;
	(void)argv;
	signals();
	init_path(env, env_shell);
	env_shell->path = get_pathm(env_shell->env_paths);
}

void	print_list(t_vars **lst)
{
	t_vars	*tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("info: %s\ttype: %d\tlength: %d\n", tmp->token, tmp->type, tmp->length);
		tmp = tmp->next;
	}
}


// int	main(int argc, char **argv, char **env)
// {
// 	char		*input;
// 	char		**line;
// 	t_env_path	*env_shell;
// 	t_vars		*list;

// 	list = NULL;
// 	env_shell = malloc(sizeof(t_env_path));
// 	init_arg(argc, argv, env, env_shell);
// 	while (1)
// 	{
// 		input = readline("minishell: ");
// 		add_history(input);
// 		line = split_arg(input);
// 		if (!close_quote(line))
// 			lexer(line, env_shell);
// 		else
// 		{
// 			printf("quote not close\n");
// 			exit_file(list, env_shell);
// 		}
// 		if (!create_list(&list, env_shell->pipes->arv, env_shell))
// 		{
// 			print_list(&list);
// 			printf("something went wrong\n");
// 			exit_file(list, env_shell);
// 		}
// 		execute_command(list, env_shell);
// 		ft_listclear(&list);
// 	}
// 	free(input);
// }

int	main(int argc, char **argv, char **env)
{
	char		*input;
	char		**line;
	t_env_path	*env_shell;
	t_vars		*list;

	list = NULL;
	env_shell = malloc(sizeof(t_env_path));
	init_arg(argc, argv, env, env_shell);
	start_shell(env_shell);
	while (1)
	{
		input = readline("minishell: ");
		add_history(input);
		line = split_arg(input);
		env_shell->last = close_quote(line);
		if (env_shell->last == 0)
		{	
			lexer(line, env_shell);
			// check_pipe_line(env_shell);
			create_list(&list, env_shell->pipes->arv, env_shell);
		}	
		else
			exit_file(list, env_shell);
		// printf("%s\n", env_shell->shelllvl);
		// if (!create_list(&list, env_shell->pipes->arv, env_shell))
		// {
		// 	printf("something went wrong\n");
		// 	//exit_file(list, env_shell);
		// }
		// for (int i = 0; env_shell->pipes->arv[i]; i++)
		// 	printf("arv1[%d]: %s\n", i, env_shell->pipes->arv[i]);
		// command_to_do(list, env_shell);
		// print_list(&list);
		execute_command(list, env_shell);
		ft_listclear(&list);
	}
	free(input);
}