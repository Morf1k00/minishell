/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/10 18:05:13 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void init_arg(int argc, char **argv, char **env, t_env_path *env_shell)
{
    (void)argc;
    (void)argv;
    // (void)env;
    init_path(env, env_shell);
}

int main(int argc, char **argv, char **env)
{
    char *input;
    char        **line;
    t_env_path *env_shell;
    while(1)
    {
        env_shell = malloc(sizeof(t_env_path));
        init_arg(argc, argv, env, env_shell);
        input = readline("minishell: ");
        line  = split_arg(input);
        if (strcmp(line[0], "exit") == 0)
            exit(0);
		if (strcmp(line[2], ">") == 0)
		{
			ft_redirect_cmd_to_file(line, line[4], env_shell);
		}
        // for (int c = 0; line[c] != NULL; c++) // test how readarguments
        //     printf("%s\t : number arg %d \n", line[c], c);
        // for (int d = 0; env_shell->env_paths[d] != NULL; d++) // test how copy env 
        //     printf("env_shell->env_paths : %s\n", env_shell->env_paths[d]);
    }
    free(input);
}
