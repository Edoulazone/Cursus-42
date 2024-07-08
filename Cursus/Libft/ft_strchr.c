/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:40:54 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/19 16:21:10 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*modifiable_string;

	modifiable_string = (char *)s;
	while (*modifiable_string != (char)c)
	{
		if (*modifiable_string == '\0')
			return (NULL);
		modifiable_string++;
	}
	return (modifiable_string);
}
