/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quots.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:57:06 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/17 15:52:41 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int close_quote(char **line)
// {
// 	int i;
// 	int sq;
// 	int dq;

// 	i = 0;
// 	sq = 0;
// 	dq = 0;
// 	while (line[i] != NULL)
// 	{
// 		if (line[i][0] == '\'')
// 			sq++;
// 		else if (line[i][0] == '\"')
// 			dq++;
// 		i++;
// 	}
// 	if (sq % 2 != 0 || dq % 2 != 0 )
// 		return(1);
// 	return(0);
// }	

// static bool check_single_quotes(char **line, int *i)
// {
//     int sq = 0;

//     if (line[*i][0] == '\'')
//     {
//         sq++;
//         (*i)++;
//         if (!line[*i])
//             return false;
//         while (line[*i] && line[*i][0] != '\'')
//             (*i)++;
//         if (!line[*i])
//             return false;
//         sq++;
//         if (line[*i] != NULL)
//             (*i)++;
//     }
//     if (sq % 2 == 0)
//         return(true);
//     return (false);
// }

// static bool check_double_quotes(char **line, int *i)
// {
//     int dq = 0;

//     if (line[*i][0] == '\"')
//     {
//         dq++;
//         (*i)++;
//         if (!line[*i])
//             return false;
//         while (line[*i] && line[*i][0] != '\"')
//             (*i)++;
//         if (!line[*i])
//             return false;
//         dq++;
//         if (line[*i] != NULL)
//             (*i)++;
//     }
//     if (dq % 2 == 0)
//         return(true);
//     return (false);
// }

// bool close_quote(char **line)
// {
//     int i = 0;

//     while (line[i])
//     {
//         if (line[i][0] == '\'')
//         {
//             if (!check_single_quotes(line, &i))
//                 return false;
//         }
//         else if (line[i][0] == '\"')
//         {
//             if (!check_double_quotes(line, &i))
//                 return false;
//         }
//         if (line[i])
//             i++;
//     }
//     return true;
// }

bool	close_quote(char **line)
{
	int	i;
	int	sq;
	int	dq;

	i = 0;
	sq = 0;
	dq = 0;
	while (line[i])
	{
		if (line[i][0] == '\'')
		{
			sq++;
			i++;
			if (!line[i])
				return (false);
			while (line[i][0] != '\'' && line[i])
				i++;
			if (!line[i])
				return (false);
			sq++;
		}
		else if (line[i][0] == '\"')
		{
			dq++;
			i++;
			if (line[i] == NULL)
				return (false);
			while (line[i][0] != '\"' && line[i])
				i++;
			if (line[i] == NULL)
				return (false);
			dq++;
		}
		if (line[i] != NULL)
			i++;
	}
	if (sq % 2 == 0 && dq % 2 == 0)
		return (true);
	return (false);
}
