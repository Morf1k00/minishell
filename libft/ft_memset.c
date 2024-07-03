/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:43:04 by dbizjano          #+#    #+#             */
/*   Updated: 2024/07/03 15:18:53 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*tmp_str;
	size_t			i;

	tmp_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		tmp_str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
