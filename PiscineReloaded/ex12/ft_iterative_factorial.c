/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:21:01 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/03 09:28:09 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;
	n = 1;

	while (nb > 0)
	{
		n = n * nb;
		nb -= 1;
	}
	return (n);
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
