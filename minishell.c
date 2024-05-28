/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/28 16:28:51 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_arg(int argc, char **argv, char **env, t_env_path *env_shell)
{
	(void)argc;
	(void)argv;
	init_path(env, env_shell);
	env_shell->path = get_pathm(env_shell->env_paths);
}

void	print_list(t_vars **lst)
{
	t_vars	*tmp;

	tmp = *lst;
	while (tmp)
	{
		//printf("info: %s\ttype: %d\tlength: %d\n", tmp->token, tmp->type, tmp->length);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	char		*input;
	char		**line;
	t_env_path	*env_shell;
	t_vars		*list;

	list = NULL;
	env_shell = malloc(sizeof(t_env_path));
    init_arg(argc, argv, env, env_shell);
    while(1)
    {
        input = readline("minishell: ");
        add_history(input);
        line  = split_arg(input);
        if (close_quote(line))
            lexer(line, env_shell);
        else
        {
			printf("quote not close\n");
			exit_file(env_shell);
		}
		if (!create_list(&list, env_shell->pipes->arv, env_shell))
		{
			printf("something went wrong\n");
			exit_file(env_shell);
		}
		print_list(&list);
		command_to_do(list, env_shell);
		execute_with_redirection(list, env_shell);
		check_pipe_line(env_shell);
		ft_listclear(&list); 
		env_shell->pipes->pipe_i = 0;
    }
    free(input);
}	

// for (int c = 0; line[c] != NULL; c++) // test how readarguments
//             printf("%s\t : number arg %d \n", line[c], c);
	// init_arg(argc, argv, env, &env_shell);
// 	while (1)
// 	{
// 		input = readline("minishel: ");
// 		if (!input)
// 			break ;
// 		add_history(input);
// 		line = split_arg(input);
// 		if (line[0] == NULL)
// 			continue ;
// 		else if (strcmp(line[0], "exit") == 0)
// 			exit(EXIT_SUCCESS);
// 		else if (strcmp(line[0], "export") == 0)
// 			execute_export_command(line, env_shell);
// 		else
// 		{
// 			if (close_quote(line))
// 				lexer(line, &env_shell);
// 			else
// 				write(STDOUT_FILENO, "quote not close\n", strlen("quote not close\n"));
// 			if (!create_list(&list, env_shell->pipes->arv, env_shell))
// 			{
// 				write(STDOUT_FILENO, "smth went wrong\n", strlen("smth went wrong\n"));
// 				exit(EXIT_FAILURE);
// 			}
// 			while (list)
// 			{
// 				if (strcmp(list->token, "echo") == 0)
// 					echo(&list);
// 				else if (strcmp(list->token, "env") == 0)
// 					ft_env(&env_shell);
// 				if (list->next)
// 					list = list->next;
// 				else
// 					break ;
// 			}
// 			ft_listclear(&list);
// 		}
// 		// free(input);
// 	}
// 	return (0);
// 			printf("%s\n", list->token);
// 		
// 		check_cmd_line(&list);
// 		while (list) // GOING THROUGH THE LIST AND LOOKING FOR "ECHO" TO EXECUTE THE COMMAND. CLEANING THE LIST.
// 		{
// 			if (strcmp(list->token, "echo") == 0)
// 				echo(&list);
// 			else if (strcmp(list->token, "env") == 0)
// 				ft_env(env_shell);
// 			if (list->next)
// 				list = list->next;
// 			else
// 				break ;
// 		}
// 		for (int c = 0; line[c] != NULL; c++) // test how readarguments
//             printf("%s\t : number arg %d \n", line[c], c);
//         if (env_shell->pipes->arv != NULL)
// 			for (int d = 0; env_shell->pipes->arv[d] != NULL; d++) // test how copy env 
//             	printf("env_shell->env_paths : %s\t %d\n", env_shell->pipes->arv[d], d);
//         for (int k = 0; env_shell->env_paths[k] != NULL; k++) // test how copy env 
//             printf("env_shell->env_paths : %s\n", env_shell->env_paths[k]);
// }