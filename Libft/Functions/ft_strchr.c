/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:40:54 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/17 14:47:49 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strchr(const char *base_string, int character)
{
	char	*modifiable_string;

	modifiable_string = (char *)base_string;
	while (*modifiable_string != character)
	{
		if (*modifiable_string == '\0')
			return (NULL);
		modifiable_string++;
	}
	return (modifiable_string);
}