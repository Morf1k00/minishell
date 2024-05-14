/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbizjano <dbizjano@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:52:38 by dbizjano          #+#    #+#             */
/*   Updated: 2022/12/20 18:55:50 by dbizjano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char *niddle, size_t n)
{
	size_t	i;
	size_t	j;

	if (!*niddle)
		return ((char *)haystack);
	j = 0;
	while (haystack[j])
	{
		i = 0;
		while (haystack[j + i] == niddle[i] && j + i < n)
		{
			if (!niddle[1 + i])
			{
				return ((char *)(haystack + j));
			}
			i++;
		}
		j++;
	}
	return (NULL);
}
