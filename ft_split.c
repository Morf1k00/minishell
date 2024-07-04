// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_split.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/11/14 14:16:22 by rkrechun          #+#    #+#             */
// /*   Updated: 2024/07/04 19:30:41 by debizhan         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "minishell.h"

// static size_t	words_count(char *s, char c)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (*s)
// 	{
// 		if (*s != c)
// 			i++;
// 		else if (*s == c && i != 0)
// 		{
// 			j++;
// 			i = 0;
// 		}
// 		s++;
// 	}
// 	if (i != 0)
// 		j++;
// 	return (j);
// }

// // static char	*word(char *s, char c)
// // {
// // 	char	*buf;

// // 	while (*s == c)
// // 		s++;
// // 	buf = s;
// // 	while (*buf && *buf != c)
// // 		buf++;
// // 	*buf = '\0';
// // 	return (s);
// // }

// static char	*word(char *s, char c)
// {
//     char	*start;
//     char	*word;
//     size_t	len = 0;

//     while (*s == c)
//         s++;
//     start = s;
//     while (*s && *s != c)
//     {
//         len++;
//         s++;
//     }
//     word = (char *)malloc(sizeof(char) * (len + 1));
//     if (!word)
//         return (NULL);
//     ft_strlcpy(word, start, len + 1); // Assuming ft_strlcpy is implemented correctly
//     return (word);
// }

// static char	**free_arr(char **arr, char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (arr[i])
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	free(s);
// 	return (NULL);
// }

// static char	**worker(char **arr, char *s1, char c, size_t j)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < j)
// 	{
// 		if (*s1 != c)
// 		{
// 			arr[i] = word(s1, c);
// 			if (!arr[i])
// 				return (free_arr(arr, s1));
// 			s1 = s1 + ft_strlen(arr[i]);
// 			i++;
// 		}
// 		s1++;
// 	}
// 	arr[i] = NULL;
// 	return (arr);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**w_arr;
// 	char	*s1;
// 	size_t	j;

// 	s1 = ft_strdup(s);
// 	if (!s1)
// 		return (NULL);
// 	j = words_count(s1, c);
// 	w_arr = (char **)malloc(sizeof(char *) * (j + 1));
// 	if (!w_arr)
// 		return (NULL);
// 	w_arr = worker(w_arr, s1, c, j);
// 	free(s1);
// 	return (w_arr);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbizjano <dbizjano@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:23:44 by dbizjano          #+#    #+#             */
/*   Updated: 2023/01/17 17:27:00 by dbizjano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

/* Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
Return value - The array of new strings resulting from the split.
NULL if the allocation fails.
 */
static int	count_return_array_size(char const *s, char c,
									int i, int del_cnt)
{
	int	enter_flag;

	enter_flag = 0;
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
	if (!s)
		return (NULL);
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
	// if (word_start)
	// 	free(word_start);
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
