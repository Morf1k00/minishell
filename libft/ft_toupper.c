/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbizjano <dbizjano@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:31:22 by dbizjano          #+#    #+#             */
/*   Updated: 2022/12/14 10:13:56 by dbizjano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int argument)
{
	if (argument >= 'a' && argument <= 'z')
		return (argument - 32);
	return (argument);
}
