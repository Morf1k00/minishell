/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:24:57 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/15 19:58:30 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int tokens_init(char *arv)
{
	// int	length;

	// length = ft_strlen(arv);
	if (arv[0] == '<' && !arv[1])
		return(LESS_THEN);
	else if (arv[0] == '<' && arv[1] == '<' && !arv[2])
		return(HEREDOC);
	else if (arv[0] == '>' && !arv[1])
		return(GREATER_THEN);
	// else if (arv[0] == '\"' && arv[length - 1] == '\"')
	// 	return (DOUBLE_QUOTES);
	// else if (arv[0] == '\'' && arv[length - 1] == '\'')
	// 	return (SINGLE_QUOTES);
	else if (arv[0] == '>' && arv[1] == '>' && !arv[2])
		return(APPEND);
	else if (arv[0] != ' ')
		return (WORD);
	else if (arv[0] == '|' && !arv[1])
		return(PIPE);
	else
		return(SPACE_T);
}