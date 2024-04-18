/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:32:53 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/17 19:26:35 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*octet1;
	unsigned char	*octet2;

	if (dst == src || n == 0)
		return (dst);
	octet1 = (unsigned char*)dst;
	octet2 = (unsigned char*)src;
	while (n >= 0)
	{
		*octet1++ = *octet2++;
		n--;
	}
	return (dst);
}