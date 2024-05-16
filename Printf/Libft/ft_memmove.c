/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:32:49 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/19 16:06:37 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*pointer1;
	const unsigned char	*pointer2;

	pointer1 = dst;
	pointer2 = (unsigned char *)src;
	i = 0;
	if (!pointer1 && !pointer2)
		return (NULL);
	if (pointer2 < pointer1)
		while (++i <= len)
			pointer1[len - i] = pointer2[len - i];
	else
		while (len-- > 0)
			*(pointer1++) = *(pointer2++);
	return (dst);
}
