/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:56:37 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/16 18:06:37 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_env_path *ep)
{
	int	i;

	i = 0;
	while (ep->env_paths[i])
	{
		ft_putstr_fd(ep->env_paths[i++], 1);
		ft_putchar_fd('\n', 1);
	}
}
