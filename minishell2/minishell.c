/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/09 16:35:08 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void init_arg(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    // (void)env;
    init_env(env);
}

int main(int argc, char **argv, char **env)
{
    init_arg(argc, argv, env);
    char *input;
    char **line;

    input = readline("minishell: ");
    line  = split_arg(input);
    for (int c = 0; line[c] != NULL; c++)
        printf("%s\n", line[c]);
    free(input);
}
