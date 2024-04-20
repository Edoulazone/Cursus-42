/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:40:37 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/20 12:36:19 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	atoi_skip(const char **str, int *pos)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*pos += 1;
		(*str)++;
	}
}

int	ft_atoi(const char *str)
{
	int		pos;
	long	number;
	long	overflow;

	number = 0;
	pos = 0;
	overflow = 0;
	atoi_skip(&str, &pos);
	while (ft_isdigit(*str))
	{
		number *= 10;
		number += (*str - 48);
		str++;
		if (overflow > number && pos % 2 == 0)
			return (-1);
		else if (overflow > number && pos % 2 == 1)
			return (0);
		overflow = number;
	}
	if (pos % 2 == 1)
		return (-number);
	return (number);
}
