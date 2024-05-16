/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:48:06 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/16 17:58:16 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"
#include <stdbool.h>

static void	copy_arv(char s, char **line, char **tmp, int *i, int *j)
{
	int	len;
	int	d;

	len = 1;
	d = *i + 1;
	(*i)++;
	while (line[d][0] != s && line[d] != NULL)
	{
		len += strlen(line[d]);
		d++;
	}
	tmp[*j] = malloc(sizeof(char) * (len + 1));
	tmp[*j][0] = '\0';
	while (*i < d)
	{
		strcat(tmp[*j], line[*i]);
		(*i)++;
	}
	tmp[*j][len + 1] = '\0';
	(*i)++;
}

static int	word_count(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
		i++;
	return (i);
}

void	lexer(char **line, t_env_path *env_shell)
{
	int		i;
	int		j;
	char	**tmp;
	int		word;

	i = 0;
	j = 0;
	word = word_count(line);
	tmp = malloc(sizeof(char *) * (word + 1));
	while (i < word)
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
	env_shell->pipes->count = j;
}
