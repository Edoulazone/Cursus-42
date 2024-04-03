/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:42:13 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/03 10:54:00 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		//write(1, &str[i], 1);
		i++;
	}
}
/*
int	main(void)
{
	char	*str;

	str = "Hello";
	ft_putstr(str);
	return (0);
}
*/
