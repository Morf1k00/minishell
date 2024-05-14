/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:48:06 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/14 16:53:28 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void copy_arv(char s, char **line, char **tmp, int *i, int *j)
{
	int len;
	int d;
	
	len = 1;
	d = *i + 1;
	while(line[d][0] != s)
	{
		len += strlen(line[d]);
		d++;
	}
	tmp[*j] = malloc(sizeof(char) * (len + 3));
	while(*i <= d)
	{
		strcat(tmp[*j], line[*i]);
		(*i)++;
	}
	tmp[*j][len + 1] = '\0';
}

// static void copy_arv2(char **line, char **tmp, int *i, int *j)
// {
// 	// int len;

// 	// len = 0;
// 	// len = strlen(line[*i]);
// 	// *tmp = malloc(sizeof(char) * len);
// 	// strlcpy(*tmp, line[*i]);
// 	tmp[*j] = strdup(line[*i]);
// }

static int word_count(char **line)
{
	int i;

	i = 0;
	while(line[i] != NULL)
		i++;
	return(i);
}

static int close_quote(char **line)
{
	int i;
	int sq;
	int dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (line[i] != NULL)
	{
		if (line[i][0] == '\'')
			sq++;
		else if (line[i][0] == '\"')
			dq++;
		i++;
	}
	if (sq % 2 != 0 || dq % 2 != 0 )
		return(1);
	return(0);
}	

void lexer(char **line, t_env_path *env_shell)
{
	int i;
	int	j;
	char **tmp;
	int word;

	i = 0;
	j = 0;
	if (close_quote(line) == 1)
		// quote_heredoc(line[i]);
		write(1, "2", 1);
	word = word_count(line);
	tmp = malloc(sizeof(char *) * (word + 1));
	while(i < word)
	{
		if (line[i][0] == '\'' || line[i][0] == '\"')
			copy_arv(line[i][0], line, tmp, &i, &j);
		else
		{
			tmp[j] = strdup(line[i]);
			i++;
		}
		j++;
	}
	tmp[j] = NULL;
	env_shell->pipes->arv = tmp;
}
