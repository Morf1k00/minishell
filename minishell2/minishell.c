/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/08 16:00:35 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_mem_env(char **env, char **tmp, int i)
{
    tmp = malloc(sizeof(char *)* 1000);
    i = 0;

    while(env[i])
    {
        tmp[i] = NULL;
        i++;
    }
}

void init_env(char **env)
{
    t_env_path dat_env;
    int i;
    int c;
    char **tmp;

    memset(&dat_env, 0, sizeof(t_env_path));
    init_mem_env(env, tmp, c);
    i = 0;
    while(i != c)
    {
        tmp[i]= strdup(env[i]);
        i++;
    }
    dat_env.env_paths = tmp;
    dat_env.count = c;
}

void init_int(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    init_env(env);
}

int main(int argc, char **argv, char **env)
{
    char *input;
    char **line;
    
    init_arg(argc, argv, env);
    while(1)
    {
        input = readline("minishell: ");
        add_history(input);
        if (strcmp(input, "exit") == 0)
            exit(0);
        line = line_read(input);

        free(input);
    }
}
