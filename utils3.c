/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:08:26 by debizhan          #+#    #+#             */
/*   Updated: 2024/07/05 13:27:23 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*quote(char *line)
{
	char	*word;

	word = malloc(2);
	if (!word)
		return (NULL);
	if (*line == '\'')
		word[0] = '\'';
	else
		word[0] = '\"';
	word[1] = '\0';
	return (word);
}

int	count(char *line)
{
	int	word;

	word = 0;
	while (*line == ' ' || *line == '\t' || *line == '\n')
		++line;
	while (*line != '\0')
	{
		++word;
		if (*line == '\'' || *line == '\"')
		{
			++line;
			while (*line != '\'' && *line != '\"' && *line != '\0')
				line++;
			if (*line == '\'' || *line == '\"')
				line++;
			continue ;
		}
		while (*line != '\'' && *line != '\"' && *line != '\n'
			&& *line != '\t' && *line != '\0' && *line != ' ')
			++line;
		while (*line == ' ' || *line == '\t' || *line == '\n')
			++line;
	}
	return (word);
}

void	freeing(t_vars *list, t_env_path *env_shell)
{
	if (list)
		ft_listclear(&list);
	if (env_shell->pipes->arv)
		free_array(env_shell->pipes->arv);
	if (env_shell->env_paths)
		free_array(env_shell->env_paths);
	if (env_shell->pipes)
		free(env_shell->pipes);
	if (env_shell->shelllvl)
		free(env_shell->shelllvl);
	if (list)
		free(list);
	if (env_shell)
		free(env_shell);
}
