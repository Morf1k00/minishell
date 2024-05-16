/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/16 14:52:56 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void init_arg(int argc, char **argv, char **env, t_env_path *env_shell)
{
    (void)argc;
    (void)argv;
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
        add_history(input);
        line  = split_arg(input);
        if (strcmp(line[0], "exit") == 0)
            exit(0);
        if (close_quote(line))
            lexer(line, env_shell);
        else
            printf("quote not close\n"); 
        if (line != NULL)
            for (int c = 0; line[c] != NULL; c++) // test how readarguments
                printf("%s\t : number arg %d \n", line[c], c);
        // if (env_shell->pipes->arv != NULL)
        //     for (int d = 0; env_shell->pipes->arv[d] != NULL; d++) // test how copy env 
        //         printf("env_shell->env_paths : %s\t %d\n", env_shell->pipes->arv[d], d);
        // for (int k = 0; env_shell->env_paths[k] != NULL; k++) // test how copy env 
        //     printf("env_shell->env_paths : %s\n", env_shell->env_paths[k]);
    }
    free(input);
}