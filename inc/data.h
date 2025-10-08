/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:33:44 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/08 15:28:04 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <sys/types.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	t_data			*data;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	last_meal_mutex;
	size_t			id;
	size_t			num_meals;
	size_t			time_last_meal_ms;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_t		*threads;
	pthread_t		monitor_thread;
	pthread_mutex_t	*mutexes;
	pthread_mutex_t	log_mutex;
	pthread_mutex_t	num_philo_fed_mutex;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	end_mutex;
	size_t			*queue;
	size_t			num_philo;
	size_t			time_to_die_ms;
	size_t			time_to_eat_ms;
	size_t			time_to_sleep_ms;
	size_t			num_times_philo_must_eat;
	size_t			initial_time_ms;
	size_t			num_philo_fed;
	bool			num_meals_active;
	bool			end;
}	t_data;

typedef enum e_log
{
	FORK,
	EAT,
	THINK,
	SLEEP,
	DIE
}	t_log;

#endif
