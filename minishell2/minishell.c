/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/10 14:08:53 by rkrechun         ###   ########.fr       */
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

    env_shell = malloc(sizeof(t_env_path));
    init_arg(argc, argv, env, env_shell);
    input = readline("minishell: ");
    line  = split_arg(input);
    // for (int c = 0; line[c] != NULL; c++)
    //     printf("%s\n", line[c]);
    // for (int d = 0; env_shell->env_paths[d] != NULL; d++)
    //     printf("env_shell->env_paths : %s\n", env_shell->env_paths[d]);
    free(input);
}
