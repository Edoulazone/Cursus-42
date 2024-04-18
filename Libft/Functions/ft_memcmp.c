/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:40:46 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/17 19:11:25 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*character1;
	unsigned char	*character2;

	character1 = (unsigned char*)s1;
	character2 = (unsigned char*)s2;
	while (n >= 0)
	{
		if (*character1 != *character2)
			return (*character1 - *character2);
		character1++;
		character2++;
		n--;
	}
	return (0);
}