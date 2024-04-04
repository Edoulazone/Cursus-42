/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:33:18 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/04 15:50:58 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	n;

	n = 1;
	while (n * n <= nb && n <= 46340)
	{
		if (n * n == nb)
			return (n);
		n++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n;
	int	x;

	n = 64;
	x = 2147395600;
	printf("%d\n", ft_sqrt(n));
	printf("%d\n", ft_sqrt(x));
	return (0);
}
*/
