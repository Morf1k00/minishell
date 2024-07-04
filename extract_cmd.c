/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:22:20 by debizhan          #+#    #+#             */
/*   Updated: 2024/07/04 19:46:47 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*command;

	tmp = NULL;
	command = NULL;
	while (*path)
	{
		if (ft_strcmp(cmd, "./minishell") == 0)
			return (cmd);
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

	command = NULL;
	tmp = NULL;
	if (!path || !cmd)
		return (NULL);
	tmp = ft_split(path, ':');
	command = get_cmd(tmp, cmd);
	// free(tmp);
	free_array(tmp);
	tmp = malloc(sizeof(char *) * 2);
	tmp[0] = command;
	tmp[1] = NULL;
	return (tmp);
}
