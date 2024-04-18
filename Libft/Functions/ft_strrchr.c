/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:41:12 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/17 14:51:36 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *base_string, int character)
{
	int	indent;

	i = ft_strlen(base_string) + 1;
	while (--i >= 0)
	{
		if (base_string[i] == (char)character)
			return ((char*)base_string + i);
	}
	return (NULL);
}