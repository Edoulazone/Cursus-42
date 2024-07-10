/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:33:14 by eschmitz          #+#    #+#             */
/*   Updated: 2024/07/10 16:41:50 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
int	ft_isdigit(int c);
void	ft_putendl(const char *s);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);

#endif