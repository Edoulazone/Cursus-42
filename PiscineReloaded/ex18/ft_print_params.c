/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:18:41 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/03 13:25:29 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <unistd.h>

void	ft_putchar(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}
*/
int	main(int av, char **ac)
{
	int	i;

	i = 1;
	while (i < av)
	{
		ft_putchar(ac[i]);
		ft_putchar("\n");
		i++;
	}
	return (0);
}
