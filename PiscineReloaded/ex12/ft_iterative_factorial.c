/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:21:01 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/04 16:32:57 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = nb;
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	while (1 < nb)
	{
		res = res * (nb - 1);
		nb--;
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	int	n;
	n = 6;

	printf("%d", ft_iterative_factorial(n));
	return (0);
}
*/
