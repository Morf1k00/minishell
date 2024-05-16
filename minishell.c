/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/16 17:02:23 by debizhan         ###   ########.fr       */
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
        lexer(line, env_shell);
		if (!create_list(&list, env_shell->pipes->arv))
		{
			printf("smth went wrong\n");
			exit(1);
		}
		// print_list(&list);
		while (list)
		{
			if (strcmp(list->token, "echo") == 0)
				ft_echo(&list);
			if (list->next)
				list = list->next;
			else
				break ;
		}
		ft_listclear(&list);
        // for (int c = 0; line[c] != NULL; c++) // test how readarguments
        //     printf("%s\t : number arg %d \n", line[c], c);
        // for (int d = 0; env_shell->pipes->arv[d] != NULL; d++) // test how copy env 
        //     printf("env_shell->env_paths : %s\t %d\n", env_shell->pipes->arv[d], d);
        // for (int k = 0; env_shell->env_paths[k] != NULL; k++) // test how copy env 
        //     printf("env_shell->env_paths : %s\n", env_shell->env_paths[k]);
    }
    free(input);
}
