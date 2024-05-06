/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:29:35 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/06 19:05:06 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

static char	*get_path(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

static char	*get_command(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;
    char *input;
    char **line;
    //int i;
    t_cmd_data data;

    //i = 0;
    data.env_paths = get_path(env);
    data.cmd_paths = ft_split(data.env_paths, ':');
    while(1)
    {
        input = readline("minishell: ");
        add_history(input);

        if (strcmp(input, "exit") == 0)
            exit(0);
        line = line_read(input);
        data.cmd = get_command(data.cmd_paths, line[0]);
        // data.cmd_args;
        data.cmd_args = ft_split(line[0], ' ');
        printf("data.cmd :%s\n", data.cmd);
        execve(data.cmd, data.cmd_args, env);
        // while (line[i])
        // {
        //     printf("%s\n", line[i]);
        //     i++;
        // }
        free(input);
    }
}
