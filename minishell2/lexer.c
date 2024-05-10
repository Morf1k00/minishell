/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:48:06 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/10 18:07:59 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void copy_arv(char s, char **line, char **tmp, int i)
{
	int len;
	int d;
	
	len = 0;
	d = i;
	while(line[i][0] != s)
	{
		len += strlen(line[i]);
		i++;
	}
	*tmp = malloc(sizeof(char) * len);
	while(line[d][0] != s)
	{
		strcat(*tmp, line[d]);
		d++;
	}
}

void copy_arv2(char **line, char **tmp, int i)
{
	int len;

	len = 0;
	len = strlen(line[i]);
	*tmp = malloc(sizeof(char) * len);
	strcpy(*tmp, line[i]);
}

static int word_count(char **line)
{
	int i;

	i = 0;
	while(line[i] != '\0')
		i++;
	return(i);
}

static int close_quote(char **line)
{
	int i;

	i = 0;
	if (line[i][0] == '\'')
		while(line[i][0] != '\'' || line[i])
			i++;
	else if (line[i][0] == '\"')
		while(line[i][0] != '\"' || line[i])
			i++;
	if (line[i] == '\0')
		return(1);
	return(0);
}	

void lexer(char **line, t_env_path *env_shell)
{
	int i;
	char **tmp;
	int word;
	int c;

	c = 0;
	i = 0;
	if (close_quote(line) == 1);
		printf("Error : Quots not close");
	word = word_count(line);
	tmp = malloc(sizeof(char *) * (word + 1));
	while(i < word)
	{
		if (line[i][0] == '\'' || line[i][0] == '\"')
			copy_arv(line[i][0], line[i], &tmp, &i);
		else
			copy_arv2(line[i], &tmp, &i);
		tmp++;
	}
	tmp[word] = NULL;
	env_shell->pipes->arv = tmp;
}