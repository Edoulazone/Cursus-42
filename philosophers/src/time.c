/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:56:12 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/11 10:16:56 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL))
		return (1);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

int	ft_usleep(int time)
{
	int	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(100);
	return (0);
}
