/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:24:57 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/15 17:18:40 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int tokens_init(char *arv)
{
	if (arv[0] == '<' && !arv[1])
		return(LESS_THEN);
	else if (arv[0] == '<' && arv[1] == '<' && !arv[2])
		return(HEREDOC);
	else if (arv[0] == '>' && !arv[1])
		return(GREATER_THEN);
	else if (arv[0] == '>' && arv[1] == '>' && !arv[2])
		return(APPEND);
	else if (arv[0] == '|' && !arv[1])
		return(PIPE);
	else if (arv[0] != ' ')
		return (WORD);
	else
		return(SPACE);
}