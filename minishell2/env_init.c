/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:06:34 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/09 16:34:51 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void path_e(char ***tmp, int *i, int *count, char **env)
{
    i = 0;
    count = 0;
    tmp = malloc(sizeof(char *) * 100);
    while (env[*count])
        (*count)++;
    while (*i < *count)
    {
        (*tmp)[*i] = NULL;
        (*i)++;
    }
    (*i) = 0;
}

void init_path(char **env)
{
    int i;
    char **tmp;
    int count;
   
    env_shell = malloc(sizeof(t_env_path));
    path_e(&tmp, &i, &count, env);
    while(i != count)
    {
        tmp[i] = strdup(env[i]);
        i++;
    }
    env_shell->count = count;
    env_shell ->env_paths = tmp;
}







// static char	*get_path(char **env)
// {
// 	while (ft_strncmp("PATH", *env, 4))
// 		env++;
// 	return (*env + 5);
// }

// static char	*get_command(char **paths, char *cmd)
// {
// 	char	*tmp;
// 	char	*command;

// 	while (*paths)
// 	{
// 		tmp = ft_strjoin(*paths, "/");
// 		command = ft_strjoin(tmp, cmd);
// 		free(tmp);
// 		if (access(command, F_OK) == 0)
// 			return (command);
// 		free(command);
// 		paths++;
// 	}
// 	return (NULL);
// }

// void init_path(t_env_path data)
// {
//     data.env_cmd_path = get_path(data.env_paths);
//     data.cmd_paths = ft_split(data.env_paths, ':');
// }