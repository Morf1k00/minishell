/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/17 17:08:01 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void init_arg(int argc, char **argv, char **env, t_env_path *env_shell)
{
    (void)argc;
    (void)argv;
    init_path(env, env_shell);
}

void	print_list(t_vars **lst)
{
	t_vars *tmp;

	tmp = *lst;
	while (tmp)
	{
		printf("info: %s\ttype: %d\tlength: %d\n", tmp->token, tmp->type, tmp->lenght);
		tmp = tmp->next;
	}
}

int main(int argc, char **argv, char **env)
{
    char		*input;
    char        **line;
    t_env_path	*env_shell;
	t_vars		*list;

	list = NULL;
    while(1)
    {
        env_shell = malloc(sizeof(t_env_path));
        init_arg(argc, argv, env, env_shell);
        input = readline("minishell: ");
        add_history(input);
        line  = split_arg(input);
        if (strcmp(line[0], "exit") == 0)
            exit(0);
        if (close_quote(line))
            lexer(line, env_shell);
        else
            printf("quote not close\n"); 
		if (!create_list(&list, env_shell->pipes->arv))
		{
			printf("smth went wrong\n");
			exit(1);
		}
			// printf("%s\n", list->token);
		// print_list(&list);
		// check_cmd_line(&list);
		while (list) // GOING THROUGH THE LIST AND LOOKING FOR "ECHO" TO EXECUTE THE COMMAND. CLEANING THE LIST.
		{
			if (strcmp(list->token, "echo") == 0)
				echo(&list);
			else if (strcmp(list->token, "env") == 0)
				ft_env(env_shell);
			if (list->next)
				list = list->next;
			else
				break ;
		}
		ft_listclear(&list); 
		// for (int c = 0; line[c] != NULL; c++) // test how readarguments
        //     printf("%s\t : number arg %d \n", line[c], c);
        // if (env_shell->pipes->arv != NULL)
		// 	for (int d = 0; env_shell->pipes->arv[d] != NULL; d++) // test how copy env 
        //     	printf("env_shell->env_paths : %s\t %d\n", env_shell->pipes->arv[d], d);
        // for (int k = 0; env_shell->env_paths[k] != NULL; k++) // test how copy env 
        //     printf("env_shell->env_paths : %s\n", env_shell->env_paths[k]);
    }
    free(input);
}
