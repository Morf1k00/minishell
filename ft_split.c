/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:16:22 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/05 11:45:28 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_return_array_size(char const *s, char c,
									int i, int del_cnt)
{
	int	enter_flag;

	enter_flag = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && enter_flag == 0)
		{
			enter_flag = 1;
			del_cnt++;
		}
		else if (s[i] == c)
			enter_flag = 0;
		i++;
	}
	return (del_cnt);
}

static char	*extract_word(char *word_start, int *word_size)
{
	int		count;
	int		word_start_cnt;
	char	*word;

	count = 0;
	word_start_cnt = 0;
	word = malloc(sizeof(char) * (*word_size + 1));
	if (!word)
		return (0);
	while (count != *word_size)
		word[count++] = word_start[word_start_cnt++];
	word[count] = '\0';
	*word_size = 0;
	return (word);
}

static int	change_values(char **word_start, const char *s,
							int *word_size, int *i)
{
	*word_start = (char *)&s[*i];
	*word_size = *word_size + 1;
	return (1);
}

static char	**fill_return_array(char **rtn, char const *s, char c, int i)
{
	char	*word_start;
	int		word_size;
	int		enter_flag;
	int		cnt;

	cnt = 0;
	word_start = NULL;
	enter_flag = 0;
	word_size = 0;
	while (s[i])
	{
		if (s[i] != c && enter_flag != 1)
			enter_flag = change_values(&word_start, s, &word_size, &i);
		else if (s[i] == c)
			enter_flag = 0;
		else
			word_size++;
		if (enter_flag == 0 && word_size > 0)
			rtn[cnt++] = extract_word(word_start, &word_size);
		i++;
		if ((size_t)i >= ft_strlen(s) && enter_flag == 1 && word_size > 0)
			rtn[cnt++] = extract_word(word_start, &word_size);
	}
	rtn[cnt] = 0;
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		del_cnt;
	int		i;

	if (!s)
	{
		return (NULL);
	}
	i = 0;
	del_cnt = 0;
	del_cnt = count_return_array_size(s, c, i, del_cnt);
	rtn = malloc(sizeof(char *) * (del_cnt + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	rtn = fill_return_array(rtn, s, c, i);
	return (rtn);
}
