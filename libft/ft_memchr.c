/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:12:12 by dbizjano          #+#    #+#             */
/*   Updated: 2023/05/08 17:43:08 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*b;
	char	ch;

	ch = c;
	b = (char *)s;
	while (n > 0)
	{
		if (*b == ch)
			return ((void *)b);
		b++;
		n--;
	}
	return (0);
}
