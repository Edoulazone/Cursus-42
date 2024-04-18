/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:40:37 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/17 19:22:31 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	int     i;
    int     pos;
    int     number;

    i = 0;
    pos = 0;
    number = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            pos++;
        i++;
    }
    while (str[i] <= '9' && str[i] >= '0')
    {
        number = number * 10;
        number = number + (str[i] - 48);
        i++;
    }
    if (pos % 2 == 1)
        return (-number);
    return (number);
}