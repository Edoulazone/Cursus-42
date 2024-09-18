/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschmitz <eschmitz@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:14:16 by eschmitz          #+#    #+#             */
/*   Updated: 2024/09/18 14:45:42 by eschmitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/types.h>

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIE "has died"
# define FORK "has taken a fork"
# define LEFT 0
# define RIGHT 1

typedef struct s_params
{
	int				num_of_philos;
	int				check_meal;
	int				over;
	int				ready;
	int				time_to_sleep;
	int				time_to_die;
	int				time_to_eat;
	int				maximum_iterations;
	long int		start;
	long int		end;
	pthread_mutex_t	*death;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print_m;
}	t_params;

typedef struct s_philo
{
	int				id;
	int				dead;
	int				iteration_number;
	long int		thread_start;
	long int		meal;
	long int		last_meal;
	long int		maximum_meal;
	pthread_t		life_tid;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_params		*parameters;
}	t_philo;

//philosophers.c
int			philosophers(t_params *parameters);

//routine.c
void		*thread_routine(void *arg);
void		ft_chill(t_philo *philo);

//utils.c
long		ft_atoi(char *str);
int			ft_isdigit(char *str);
int			error_msg(char *str, t_params *parameters, t_philo *philo,
				int malloc);

//utils2.c
int			check_death(t_philo *philo);
int			check_meals(int last, t_philo philo);
int			get_time(void);
int			ft_usleep(int time);
void		print_action(char *str, t_philo *philo);

#endif