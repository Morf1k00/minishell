/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:48:06 by rkrechun          #+#    #+#             */
/*   Updated: 2024/06/25 14:27:10 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static char	check_char(char c)
// {
// 	if (c == '\'')
// 		return ('\'');
// 	else if (c == '\"')
// 		return ('\"');
// 	return ('\0');
// }

// static void	copy_arv(char **line, char **tmp, int *i, int *j)
// {
// 	int		len;
// 	int		d;
// 	char	s;

// 	len = 1;
// 	(*i)++;
// 	d = *i;
// 	s = check_char(line[d - 1][0]);
// 	while (line[d][0] != s && line[d] != NULL)
// 	{
// 		len += strlen(line[d]);
// 		d++;
// 	}
// 	tmp[*j] = malloc(sizeof(char) * (len + 1));
// 	tmp[*j][0] = '\0';
// 	while (*i < d)
// 	{
// 		strcat(tmp[*j], line[*i]);
// 		(*i)++;
// 	}
// 	tmp[*j][len + 1] = '\0';
// 	(*i)++;
// }

// static int	word_count(char **line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] != NULL)
// 		i++;
// 	return (i);
// }

// void	lexer(char **line, t_env_path *env_shell)
// {
// 	int		i;
// 	int		j;
// 	char	**tmp;
// 	int		word;

// 	i = 0;
// 	j = 0;
// 	word = word_count(line);
// 	tmp = malloc(sizeof(char *) * (word + 1));
// 	while (i < word)
// 	{
// 		if (line[i][0] == '\'' || line[i][0] == '\"')
// 			copy_arv(line, tmp, &i, &j);
// 		else
// 		{
// 			tmp[j] = strdup(line[i]);
// 			i++;
// 		}
// 		j++;
// 	}
// 	tmp[j] = NULL;
// 	env_shell->pipes->arv = tmp;
// 	env_shell->pipes->count = j;
// }

// static char	check_char(char c)
// {
// 	if (c == '\'')
// 		return ('\'');
// 	else if (c == '\"')
// 		return ('\"');
// 	return ('\0');
// }

// static void	copy_arv(char **line, char **tmp, int *i, int *j)
// {
// 	int		len;
// 	int		d;
// 	char	s;

// 	len = 1;
// 	(*i)++;
// 	d = *i;
// 	s = check_char(line[d - 1][0]);
// 	while (line[d] != NULL && line[d][0] != s)
// 	{
// 		len += strlen(line[d]);
// 		d++;
// 	}
// 	tmp[*j] = malloc(sizeof(char) * (len + 1));
// 	tmp[*j][0] = '\0';
// 	while (*i < d)
// 	{
// 		strcat(tmp[*j], line[*i]);
// 		(*i)++;
// 	}
// 	tmp[*j][len] = '\0';
// 	(*i)++;
// }
static void copy_arv(char **line, char **tmp, int *i, int *j) {
    int len = 0;
    int start = *i;
    char quote_char = line[*i][0];

    (*i)++;
    while (line[*i] != NULL && line[*i][0] != quote_char) {
        len += strlen(line[*i]) + 1; // +1 for space or null terminator
        (*i)++;
    }

    tmp[*j] = malloc(sizeof(char) * (len + 1));
    tmp[*j][0] = '\0';

    for (int k = start + 1; k < *i; k++) {
        strcat(tmp[*j], line[k]);
        if (k < *i - 1) {
            strcat(tmp[*j], " ");
        }
    }

    (*j)++;
    (*i)++;
}


static int	word_count(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
	{
		if (line[i])
		i++;}
	return (i);
}

// void	lexer(char **line, t_env_path *env_shell)
// {
// 	int		i;
// 	int		j;
// 	char	**tmp;
// 	int		word;

// 	i = 0;
// 	j = 0;
// 	word = word_count(line);
// 	tmp = malloc(sizeof(char *) * (word + 1));
// 	while (i < word)
// 	{
// 		if (line[i][0] == '\'' || line[i][0] == '\"')
// 			copy_arv(line, tmp, &i, &j);
// 		else
// 		{
// 			tmp[j] = strdup(line[i]);
// 			i++;
// 		}
// 		j++;
// 	}
// 	tmp[j] = NULL;
// 	env_shell->pipes->arv = tmp;
// 	env_shell->pipes->count = j;
// }

void lexer(char **line, t_env_path *env_shell) {
    int i = 0;
    int j = 0;
    char **tmp;
    int word = word_count(line);

    tmp = malloc(sizeof(char *) * (word + 1));
    while (i < word) {
        if (line[i][0] == '\'' || line[i][0] == '\"') {
            copy_arv(line, tmp, &i, &j);  // Function to handle quoted strings
        } else if (line[i][0] == '|' || line[i][0] == '>' || line[i][0] == '<') {
            tmp[j++] = strdup(line[i++]);  // Copy the special character as a separate token
        } else {
            tmp[j++] = strdup(line[i++]);  // Copy the word
        }
    }
    tmp[j] = NULL;
    env_shell->pipes->arv = tmp;
    env_shell->pipes->count = j;
}

