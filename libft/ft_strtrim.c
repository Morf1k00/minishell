/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbizjano <dbizjano@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:04:57 by dbizjano          #+#    #+#             */
/*   Updated: 2023/01/07 23:53:14 by dbizjano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string. */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	start;
	unsigned char	i;
	unsigned char	len;
	char			*rlt;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	len = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (start == len)
		return (ft_strdup(""));
	while (start < len && ft_strchr(set, s1[len]))
		len--;
	len = (len - start + 2);
	rlt = (char *)malloc(sizeof(char) * (len));
	if (!rlt)
		return (NULL);
	len -= 1;
	while (i < len)
		rlt[i++] = s1[start++];
	rlt[i] = '\0';
	return (rlt);
}
