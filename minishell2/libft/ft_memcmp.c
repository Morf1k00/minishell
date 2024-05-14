/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbizjano <dbizjano@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:52:53 by dbizjano          #+#    #+#             */
/*   Updated: 2022/12/22 21:28:14 by dbizjano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int				i;
	int				c1;
	int				c2;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)str1;
	tmp2 = (unsigned char *)str2;
	i = 0;
	if (!n)
		return (0);
	while (n--)
	{
		c1 = tmp1[i];
		c2 = tmp2[i];
		if (c1 != c2)
			break ;
		i++;
	}
	return (c1 - c2);
}
