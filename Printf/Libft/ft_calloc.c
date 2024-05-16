/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:21:32 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/20 13:25:33 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	test;

	test = count * size;
	if (size != 0 && count != test / size)
		return (NULL);
	pointer = malloc(count * size);
	if (pointer == NULL)
		return (pointer);
	ft_bzero(pointer, size * count);
	return (pointer);
}
