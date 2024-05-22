/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:43:49 by dbizjano          #+#    #+#             */
/*   Updated: 2024/05/17 17:20:33 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	algorythm(const char *str, size_t i, int result, int minus)
{
	while (i < ft_strlen(str))
	{
		if ((!(str[i] >= 48 && str[i] <= 57))
			&& (str[i] != '\f' && str[i] != '\t' && str[i] != '\n'
				&& str[i] != '\r' && str[i] != '\v'
				&& str[i] != '-' && str[i] != '+' && str[i] != ' '))
			break ;
		if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
			minus = -1;
		if (str[i] == '-' || str[i] == '+')
		{
			if (result != 0 || (str[i + 1] < '0' || str[i + 1] > '9'))
				break ;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = (result * 10) + (str[i] - '0');
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				break ;
		}
		else if (result != 0)
			break ;
		i++;
	}
	return (result * minus);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		minus;
	size_t	i;

	i = 0;
	minus = 1;
	result = 0;
	return (algorythm(str, i, result, minus));
}
