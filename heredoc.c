/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:24:50 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/30 14:29:00 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void heredoc_min(t_env_path *env_shell)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env_shell->pipes->arv[i] != NULL)
	{
		if (env_shell->pipes->arv[i][0] == '<'
			&& env_shell->pipes->arv[i][1] == '<'
			&& env_shell->pipes->arv[i][2] == '\0')
			j++;
		i++;
		env_shell->pipes->heredoc_i = j;
	}
}