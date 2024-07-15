/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:42:03 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/04 17:11:57 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	word(char **tmp, char **line, int *i)
{
	tmp[*i] = word_cpy(*line);
	(*i)++;
	while (**line != '\'' && **line != '\"' && **line != '\n'
		&& **line != '\t' && **line != '\0' && **line != ' ')
	{
		++(*line);
	}
}

static void	kostil(char *line)
{
	while (*line != '\'' && *line != '\"' && *line != '\0')
		line++;
	if (*line == '\'' || *line == '\"')
		line++;
}

static void	kostil2(char **tmp, char *line, int i, int j)
{
	while (*line != '\0')
	{
		if (*line == '\'' || *line == '\"')
		{
			tmp[i] = quote(line);
			if (!tmp[i])
			{
				while (j < i)
					free(tmp[j++]);
				return ;
			}
			i++;
			line++;
			kostil(line);
			continue ;
		}
		word(tmp, &line, &i);
		while (*line == ' ' || *line == '\t' || *line == '\n')
			line++;
	}
}

void	init_word(char **tmp, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*line == ' ' || *line == '\t' || *line == '\n')
		line++;
	kostil2(tmp, line, i, j);
}

char	**split_arg(char *line)
{
	char	**tmp;
	int		word_count;

	word_count = count(line);
	tmp = malloc(sizeof(char *) * (word_count + 1));
	if (!tmp)
		return (NULL);
	init_word(tmp, line);
	tmp[word_count] = NULL;
	return (tmp);
}
