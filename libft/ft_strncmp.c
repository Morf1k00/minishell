/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:22:07 by dbizjano          #+#    #+#             */
/*   Updated: 2023/02/22 23:28:17 by debizhan         ###   ########.fr       */
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
		if (c1 != c2 || str1[i] == '\0' || str2[i] == '\0')
			break ;
		i++;
	}
	return (c1 - c2);
}
