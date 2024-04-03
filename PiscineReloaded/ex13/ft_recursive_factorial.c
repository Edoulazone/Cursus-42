/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:23:57 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/03 10:32:45 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	n;
	n = 1;
	if (nb > 0)
		n = n * nb;
	else
		return (n);
	return (n * ft_recursive_factorial(nb - 1));
}

#include <stdio.h>

int	main(void)
{
	int	n;
	n = 6;

	printf("%d", ft_recursive_factorial(n));
	return (0);
}
