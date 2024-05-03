/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:02:12 by rkrechun          #+#    #+#             */
/*   Updated: 2024/05/03 10:25:02 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main()
{
    char *input;

    while(1)
    {
        input = readline("minishell:");
        if (ft_strcmp(input, "exit") == 0)
            exit(0);
        printf(input);
        free(input);
    }
}
