/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:22:07 by dbizjano          #+#    #+#             */
/*   Updated: 2024/05/30 15:15:02 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (n <= 0)
		return (0);
	while (n--)
	{
		c1 = str1[i];
		c2 = str2[i];
		if (c1 != c2 || str1[i] == '\0' || str2[i] == '\0' )
			break ;
		i++;
	}
	return (c1 - c2);
}
