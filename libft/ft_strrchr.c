/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:39:24 by dbizjano          #+#    #+#             */
/*   Updated: 2023/05/08 17:46:00 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	char	ch;

	ch = c;
	ptr = NULL;
	if (!ft_isascii(ch))
		return (NULL);
	while (*str)
	{
		if (*str == ch)
			ptr = (char *)str;
		str++;
	}
	if (*str == ch)
		return ((char *)str);
	else
		return (ptr);
}
