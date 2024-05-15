/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:48:06 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/15 17:08:06 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

static void copy_arv(char s, char **line, char **tmp, int *i, int *j)
{
	int len;
	int d;
	
	len = 1;
	d = *i + 1;
	while(line[d][0] != s && line[d] != NULL)
	{
		len += strlen(line[d]);
		d++;
	}
	tmp[*j] = malloc(sizeof(char) * (len + 3));
	tmp[*j][0] = '\0';
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

		write(1, "2", 1);
	word = word_count(line);
	tmp = malloc(sizeof(char *) * (word + 1));
	while(i < word)
	{
		if (line[i][0] == '\'' || line[i][0] == '\"')
		{
			copy_arv(line[i][0], line, tmp, &i, &j);
		}
		else
		{
			tmp[j] = strdup(line[i]);
			i++;
		}
		j++;
	}
	tmp[j] = NULL;
	env_shell->pipes->arv = tmp;
	env_shell->pipes->count = j;
	//free(tmp);
}
