/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:32:54 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/10 17:24:37 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_find_redir(t_pipes *db)
{
	int	i;
	int	input;
	int	output;

	i = 0;
	while (db->arv[i])
	{
		if (ft_strncmp(">", db->arv[i], 1) == 0)
			ft_redirect_cmd_to_file(db->arv[i - 1], db->arv[i + 1]);
		
	}
}

void	ft_check_redir(t_pipes *db, int output)
{
	int	fd;

	
}