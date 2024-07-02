/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:libft/ft_strcmp.c
/*   Created: 2024/07/02 14:00:24 by debizhan          #+#    #+#             */
/*   Updated: 2024/07/02 14:00:37 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
=======
/*   Created: 2024/06/03 16:08:56 by rkrechun          #+#    #+#             */
/*   Updated: 2024/07/01 13:10:35 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
>>>>>>> rostik:quots2.c
