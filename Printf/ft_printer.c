/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:41:49 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/29 12:38:44 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return(ft_putstr("(null)"));
	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}

int	ft_putptr(void *ptr)
{
	unsigned long	ptr_check;
	int				res;

	ptr_check = (unsigned long)ptr;
	res = 0;
	if (ptr_check >= 16)
		res += ft_putptr((void *)(ptr_check / 16));
	res += ft_putchar("0123456789abcdef"[ptr_check % 16]);
	return (res);
}
