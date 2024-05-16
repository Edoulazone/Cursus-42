/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:41:12 by eschmitz          #+#    #+#             */
/*   Updated: 2024/04/19 16:10:54 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *base_string, int character)
{
	int	indent;

	indent = ft_strlen(base_string) + 1;
	while (--indent >= 0)
	{
		if (base_string[indent] == (char)character)
			return ((char *)base_string + indent);
	}
	return (NULL);
}
