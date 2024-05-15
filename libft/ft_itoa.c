/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbizjano <dbizjano@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:14:36 by dbizjano          #+#    #+#             */
/*   Updated: 2022/12/22 20:17:04 by dbizjano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*assigment(long tmp, size_t bytes, int sign)
{
	char	*ptr;

	if (tmp == 0)
	{
		ptr = malloc(sizeof(char) * 2);
		if (!(ptr))
			return (NULL);
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	ptr = malloc(sizeof(char) * bytes + 1);
	if (!(ptr))
		return (NULL);
	if (sign == -1)
		ptr[0] = '-';
	ptr[bytes] = '\0';
	while (bytes > 0 && tmp >= 1)
	{
		ptr[bytes - 1] = tmp % 10 + 48;
		tmp = tmp / 10;
		bytes--;
	}
	return (ptr);
}

char	*ft_itoa(int num)
{
	size_t	bytes;
	long	tmp;
	int		sign;
	long	tmp1;

	tmp1 = num;
	sign = 1;
	bytes = 0;
	if (tmp1 < 0)
	{
		sign = -1;
		bytes++;
	}
	tmp1 = tmp1 * sign;
	tmp = tmp1;
	while (tmp1 >= 1)
	{
		tmp1 = tmp1 / 10;
		bytes++;
	}
	return (assigment(tmp, bytes, sign));
}
