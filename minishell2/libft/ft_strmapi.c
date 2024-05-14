/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbizjano <dbizjano@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:43:01 by dbizjano          #+#    #+#             */
/*   Updated: 2023/01/07 23:47:07 by dbizjano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rtn;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	rtn = ft_strdup(s);
	if (rtn == NULL)
		return (NULL);
	while (s[i])
	{
		rtn[i] = f(i, s[i]);
		i++;
	}
	return (rtn);
}
