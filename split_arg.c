/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:42:03 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/17 16:43:41 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	word(char **tmp, char **line, int *i)
{
	tmp[*i] = word_cpy(*line);
	(*i)++;
	while (**line != '\'' && **line != '\"' && **line != '\n'
		&& **line != '\t' && **line != '\0' && **line != ' ')
		++(*line);
}

char	*quote(char *line)
{
	char	*word;

	word = malloc(2);
	if (*line == '\'')
		word[0] = '\'';
	else
		word[0] = '\"';
	word[1] ='\0';
	return (word);
}

void	init_word(char **tmp, char *line)
{
	int	i;

	i = 0;
	while (*line == ' ' || *line == '\t' || *line == '\n')
		line++;
	while (*line != '\0')
	{
		if (*line == '\'' || *line == '\"')
		{
			tmp[i] = quote(line);
			i++;
			line++;
			continue ;
		}
		if (*line == ' ')
		{
			tmp[i] = malloc(2);
			tmp[i][0] = ' ';
			tmp[i][1] = '\0';
			i++;
			line++;
			continue ;
		}
		word(tmp, &line, &i);
	}
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
		if (*line == '\'' || *line == '\"' || *line == ' ')
		{
			++line;
			continue ;
		}
		while (*line != '\'' && *line != '\"' && *line != '\n'
			&& *line != '\t' && *line != '\0' && *line != ' ')
			++line;
	}
	return (word);
}

char	**split_arg(char *line)
{
	char	**tmp;
	int		word;

	word = count(line);
	tmp = malloc(sizeof(char *) * (word + 1));
	init_word(tmp, line);
	tmp[word] = NULL;
	return  (tmp);
}
