/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:03:19 by eschmitz          #+#    #+#             */
/*   Updated: 2024/06/11 19:04:04 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	else
		return (0);
}

static int	ft_countwords(const char *str, char c)
{
	int	sign;
	int	count;

	sign = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && sign == 0)
		{
			sign = 1;
			count++;
		}
		else if (*str == c)
			sign = 0;
		str++;
	}
	return (count);
}

static int	free_bird(char **arr, int k)
{
	if (arr[k - 1] == NULL)
	{
		while (k > 0)
		{
			free(arr[k - 1]);
			k--;
		}
		return (1);
	}
	return (0);
}

static int	array_put(char **array, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		if (is_sep(s[i], c))
			i++;
		else
		{
			while (s[i + j] && !is_sep(s[i + j], c))
				j++;
			array[k++] = (char *)malloc((j + 1) * sizeof(char));
			if (free_bird(array, k) == 1)
				return (1);
			ft_strlcpy(array[k - 1], s + i, j + 1);
		}
		i = i + j;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_countwords(s, c);
	buffer = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	if (array_put(buffer, s, c))
	{
		free(buffer);
		return (NULL);
	}
	buffer[word_count] = NULL;
	return (buffer);
}