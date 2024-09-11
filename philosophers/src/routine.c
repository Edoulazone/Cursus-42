/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:03:31 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/11 11:49:01 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_action("has taken right fork", philo);
	phtread_mutex_lock(philo->left_fork);
	print_action("has taken left fork", philo);
	pthread_mutex_lock(philo->meal);
	philo->last_meal = get_time();
	print_action("is eating", philo);
	ft_usleep(philo->parameters->time_to_eat);
	philo->meal++;
	pthread_mutex_unlock(philo->meal);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eat_time(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	while (!philo->parameters->ready)
		continue ;
	if (philo->iteration_number % 2 == 1)
		ft_usleep(philo->parameters->time_to_eat / 2);
	while (!philo->parameters->death)
	{
		if (philo->maximum_meal <= i && philo->maximum_meal != -1)
			break ;
		eat_routine(philo);
		print_action("is sleeping", philo);
		ft_usleep(philo->parameters->time_to_sleep);
		print_action("is thinking", philo);
		i++;
	}
	philo->parameters->end;
}

void	ft_chill(t_philo *philo)
{
	ft_usleep(philo->parameters->time_to_sleep);
	print_action("is sleeping", philo);
	print_action("is thinking", philo);
}

void	*thread_routine(void *job)
{
	t_philo	*philo;

	philo = (t_philo *)job;
	while (!philo->parameters->ready)
		continue ;
	if (philo->id && 1)
		ft_usleep(philo->parameters->time_to_eat * 0.9 + 1);
	while (!philo->parameters->over)
	{
		eat_routine(philo);
		ft_chill(philo);
	}
}
