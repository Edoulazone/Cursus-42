/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:37:17 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/19 16:04:23 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		size;
	long	copy_number;

	size = get_size(n);
	copy_number = n;
	if (n < 0)
	{
		size++;
		copy_number *= -1;
	}
	number = (char *)malloc(size + 1);
	if (!number)
		return (NULL);
	number[size] = '\0';
	while ((--size) >= 0 && copy_number >= 0)
	{
		number[size] = ((copy_number % 10) + '0');
		copy_number /= 10;
	}
	if (number[0] == '0' && n != 0)
		number[0] = '-';
	return (number);
}
