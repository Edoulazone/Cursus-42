/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:12:25 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/11 11:54:20 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	initialise_thread(t_params *p, t_philo *philo)
{
	int	i;

	i = -1;
	while (i < p->num_of_philos)
	{
		philo[i].right_fork = philo[(i + 1) % p->num_of_philos].left_fork;
		if (pthread_create(&philo[i].life_tid, NULL,
				&thread_routine, &philo[i]) == -1)
			return (error_msg("Error: Failed to create thread\n", p, 0, 1));
	}
}

int	philosophers(t_params *parameters)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * parameters->num_of_philos);
	if (!philo || initialise_philo(parameters, philo))
		return (EXIT_FAILURE);
	if (initialise_thread(parameters, philo))
		return (EXIT_FAILURE);
	return (0);
}
