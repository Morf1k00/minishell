/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:22:14 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/15 20:04:08 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_n(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
			i++;
	while(str[i])
	{
		if (str[i] == 'n')
			i++;
		else
			return (0);
	}
	return (1);
}

void	skip_spaces(t_vars *tmp)
{
	while (tmp && tmp->token[0] == ' ')
		tmp = tmp->next;
}

void	ft_echo(t_vars **lst)
{
	int		nl;
	t_vars	*tmp;

	nl = 1;
	tmp = *lst;
	if (tmp->next)
	{
		tmp = tmp->next;
		skip_spaces(tmp);
		if (check_n(tmp->token))
			nl = 0;
		skip_spaces(tmp);
		while (tmp)
		{
			if (tmp->type == WORD)
				ft_putstr_fd(tmp->token, 1);
			if (tmp->type == SPACE_T)
				write(1, "\n", 1);
			if (tmp->type != WORD && tmp->type != SPACE_T)
				break ;
			tmp = tmp->next;
		}
	}
	if (nl == 1)
		write(1, "\n", 1);
}