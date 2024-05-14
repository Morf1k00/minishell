/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbizjano <dbizjano@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:34:04 by dbizjano          #+#    #+#             */
/*   Updated: 2022/12/19 21:37:56 by dbizjano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	j;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (dstsize == 0 || !dst)
		return (s_len);
	i = 0;
	j = d_len;
	if (d_len > dstsize)
		return (s_len + dstsize);
	else
	{
		while (src[i] && (d_len + i) < dstsize)
			dst[j++] = src[i++];
		if ((d_len + i) == dstsize && d_len < dstsize)
			dst[j - 1] = '\0';
		else
			dst[j] = '\0';
	}
	return (s_len + d_len);
}
