/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbizjano <dbizjano@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:30:13 by dbizjano          #+#    #+#             */
/*   Updated: 2022/12/13 12:49:28 by dbizjano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	a;
	int	b;

	a = ft_isalpha(c);
	b = ft_isdigit(c);
	if (a == 1 || b == 1)
		return (1);
	else
		return (0);
}
