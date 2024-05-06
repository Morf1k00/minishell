/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbizjano <dbizjano@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:04:27 by dbizjano          #+#    #+#             */
/*   Updated: 2022/12/22 21:25:54 by dbizjano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	tmp1 = (char *)dest;
	tmp2 = (char *)src;
	i = 0;
	if (!(dest || src))
		return (NULL);
	while (n--)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (tmp1);
}
