/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:40:43 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/17 19:10:12 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*new_string;

	new_string = (unsigned char *)base_string;
	while (n >= 0)
	{
		if (*new_string == (unsigned char)c)
			return (new_string);
		new_string++;
		n--;
	}
	return (NULL);
} 