/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:22:14 by debizhan          #+#    #+#             */
/*   Updated: 2024/05/17 17:04:20 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_spaces(t_vars **tmp)
{
	if (!(*tmp))
		return ;
	while (*tmp)
	{
		if ((*tmp)->token[0] == ' ')
			*tmp = (*tmp)->next;
		else
			break ;
	}
}

static int	check_n(t_vars **str)
{
	int	i;

	i = 0;
	if (!*str)
		return (0);
	if ((*str)->token[0] == '-')
		i++;
	while ((*str)->token[i])
	{
		if ((*str)->token[i] == 'n')
			i++;
		else
			return (0);
	}
	*str = (*str)->next;
	return (1);
}

void	echo2(t_vars **tmp)
{
	if ((*tmp)->type == WORD)
	{
		ft_putstr_fd((*tmp)->token, 1);
		*tmp = (*tmp)->next;
	}
	else if ((*tmp)->type == SPACE_T)
	{
		skip_spaces(tmp);
		if (*tmp)
			ft_putchar_fd(' ', 1);
	}
}

void	echo(t_vars **lst)
{
	int		nl;
	t_vars	*tmp;

	nl = 1;
	tmp = *lst;
	if (tmp->next)
	{
		tmp = tmp->next;
		skip_spaces(&tmp);
		if (check_n(&tmp))
			nl = 0;
		skip_spaces(&tmp);
		while (tmp)
		{
			echo2(&tmp);
			if (!tmp || (tmp->type != WORD && tmp->type != SPACE_T))
				break ;
		}
	}
	if (nl == 1)
		write(1, "\n", 1);
}
