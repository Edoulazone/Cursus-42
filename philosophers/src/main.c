/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:12:56 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/11 10:15:02 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(char *str, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(philo->parameters->death);
	if (philo->parameters->over)
	{
		pthread_mutex_unlock(philo->parameters->death);
		return (0);
	}
	printf("%ldms %d %s\n", get_time() - philo->thread_start, philo->id, str);
	pthread_mutex_unlock(philo->parameters->death);
}

int	initialise_philo(t_params *p, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < p->num_of_philos)
	{
		philo[i].id = i;
		philo[i].dead = 0;
		philo[i].iteration_number = 0;
		philo[i].thread_start = 0;
		philo[i].meal = 0;
		philo[i].parameters = p;
		philo[i].left_fork = &p->fork[i];
		philo[i].right_fork = 0;
	}
	return (0);
}

static int	initialise_params_mutex(t_params *p)
{
	int	i;

	i = -1;
	p->death = 0;
	p->fork = 0;
	p->death = malloc(sizeof(pthread_mutex_t));
	if (!p->death)
		return (error_msg("Error: Mutex death; malloc failed\n", p, 0, 1));
	p->fork = malloc(sizeof(pthread_mutex_t) * p->num_of_philos);
	if (!p->fork)
		return (error_msg("Error: Mutex fork; malloc failed\n", p, 0, 1));
	if (pthread_mutex_init(p->death, NULL) == -1)
		return (error_msg("Error: Mutex init failed\n", p, 0, 1));
	while (++i < p->num_of_philos)
		if (pthread_mutex_init(&p->fork[i], NULL) == -1)
			return (error_msg("Error: Mutex init failed\n", p, 0, 1));
	return (0);
}

static int	initialise_params(t_params *p, char **argv)
{
	int	mutex;

	mutex = -1;
	p->num_of_philos = ft_atoi(argv[1]);
	p->time_to_die = ft_atoi(argv[2]);
	p->time_to_eat = ft_atoi(argv[3]);
	p->time_to_sleep = ft_atoi(argv[4]);
	p->maximum_iterations = -1;
	p->check_meal = 0;
	p->start = 0;
	p->ready = 0;
	if (argv[5])
	{
		p->check_meal = 1;
		p->maximum_iterations = ft_atoi(argv[5]);
	}
	p->over = 0;
	if (p->num_of_philos > 0)
		mutex = initialise_params_mutex(p);
	return (mutex || p->num_of_philos <= 0 || p-> time_to_die <= 0
		|| p->time_to_die <= 0 || p->time_to_sleep <= 0
		|| p->maximum_iterations == 0);
}

int	main(int argc, char **argv)
{
	t_params	*p;

	if (argc != 5 && argc != 6)
		return (error_msg("Error: Invalid arguments\n", &p, 0, 1));
	initialise_params(&p, argv);
	if (philosophers(&p))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
