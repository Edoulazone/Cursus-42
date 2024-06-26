/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:47:49 by eschmitz          #+#    #+#             */
/*   Updated: 2024/06/04 17:48:34 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<unistd.h>
#include <stdio.h>

int ft_print_char(char c, int ct)
{
  write(1, &c, 1);
  ct++;
  return (ct);
}

int ft_print_int(long n, int ct)
{
  if (n < 0)
  {
    write(1, "-", 1);
    ct++;
    n = -n;
  }
  if (n >= 10)
    ct = ft_print_int(n /10, ct);
  ct = ft_print_char(n % 10 + '0', ct);
  return (ct);
}

int ft_strlen(char *str)
{
  int i = 0;
  
  while (str[i])
    i++;
  return (i);
}

int ft_print_str(char *str, int ct)
{
  if (str)
  {
    write(1, str, ft_strlen(str));
    ct += ft_strlen(str);
  }
  else
    ct = ft_print_str("(null)", ct);
  return (ct);
}

int ft_print_hex(unsigned int n, int ct)
{
  if (n >= 16)
    ct = ft_print_hex(n / 16, ct);
  n = n % 16;
  if (n < 10)
    ct = ft_print_char(n + '0', ct);
  else
    ct = ft_print_char(n + 87, ct);
  return (ct);
}

int ft_arg(char c, va_list ap, int ct)
{
  if (c == 'd')
    ct = ft_print_int(va_arg(ap, int), ct);
  else if (c == 's')
    ct = ft_print_str(va_arg(ap, char *), ct);
  else if (c == 'x')
    ct = ft_print_hex(va_arg(ap, unsigned int), ct);
  return (ct);
}

int ft_printf(const char *str, ...)
{
  int i;
  int ct;
  va_list ap;
  
  i = 0;
  ct = 0;
  va_start(ap, str);
  while (str[i])
  {
    if (str[i] != '%')
    {
      write(1, &str[i], 1);
      ct++;
    }
    else
      ct = ft_arg(str[++i], ap, ct);
    i++;
  }
  va_end(ap);
  return(ct);
}

int main()
{
	int n = 198892;
	char c[] = "hello world";
	int ct, ct1;

	ct = ft_printf("  %d %s %x", n, c, n);
	ct1 = printf("\n  %d %s %x", n, c, n);
	printf ("\n %d %d", ct, ct1);
}