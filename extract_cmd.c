/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:22:20 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/27 17:22:55 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		path++;
	}
	return (NULL);
}

char	**extract_cmd(char *cmd, char *path)
{
	char	*command;
	char	**tmp;

	tmp = ft_split(path, ':');
	// for (size_t i = 0; tmp[i] != NULL; i++)
	// {
	// 	printf("tmp[%zu] = %s\n", i, tmp[i]);
	// }
	command = get_cmd(tmp, cmd);
	free(tmp);
	tmp = malloc(sizeof(char *) * 2);
	tmp[0] = command;
	tmp[1] = NULL;
	return (tmp);
}
