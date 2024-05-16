/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:16:10 by eschmitz          #+#    #+#             */
/*   Updated: 2024/05/15 18:54:37 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert(unsigned int num, char *set)
{
	static char	buffer[100];
	char		*ptr;
	int			base;

	base = ft_strlen(set);
	ptr = &buffer[99];
	*ptr = '\0';
	*--ptr = set[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = set[num % base];
		num /= base;
	}
	return (ptr);
}

int	check_format(const char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_putptr(va_arg(args, void *)) + 2);
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putstr(
				ft_convert(va_arg(args, unsigned int), "0123456789")));
	else if (c == 'x')
		return (ft_putstr(
				ft_convert(va_arg(args, unsigned int), "0123456789abcdef")));
	else if (c == 'X')
		return (ft_putstr(
				ft_convert(va_arg(args, unsigned int), "0123456789ABCDEF")));
	else if (c == '%')
		return (ft_putchar('%'));
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		length;

	i = -1;
	length = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
			length += check_format(str[++i], args);
		else if (str [i] != '%' || str[i + 1])
			length += ft_putchar(str[i]);
	}
	va_end (args);
	return (length);
}
// #include <stdio.h>

// int main(int argc, char const *argv[])
// {
// 	(void)argc;
// 	(void)argv;
// 	// int result1 = ft_printf(argv[1], argv[2]);
// 	// printf("\n%d\n", result1);
// 	// printf("\n\n-----------------------------\n\n");
// 	// int result2 = printf(argv[1], argv[2]);
// 	// printf("\n%d\n", result2);
// 	// ft_printf("%X\n", 42);
// 	ft_printf("%d\n", ft_printf("hey"));
// 	printf("%d\n", printf("%s\\%%1456", "hey"));

// 	return 0;
// }
