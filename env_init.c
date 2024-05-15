/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:06:34 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/15 15:40:38 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_path(char **env, t_env_path *env_shell)
{
    char **tmp;
    int count;
    int i;

    count = 0;
    i = 0;
    tmp = malloc(sizeof(char *) * 100);
    while (env[count])
        count++;
    while(i != count)
    {
        tmp[i] = strdup(env[i]);
        i++;
    }
    tmp[i] = NULL;
    env_shell->count = count;
    env_shell->env_paths = tmp;
    env_shell->pipes = malloc(sizeof(t_pipes ));
    env_shell->vars = malloc(sizeof(t_vars));
}

