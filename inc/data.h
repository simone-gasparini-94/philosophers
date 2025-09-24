/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:33:44 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/24 12:59:24 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <sys/types.h>
# include <pthread.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	t_data			*data;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	size_t			id;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	pthread_t		*threads;
	pthread_mutex_t	*mutexes;
	size_t			num_philo;
	size_t			time_to_die_ms;
	size_t			time_to_eat_ms;
	size_t			time_to_sleep_ms;
	size_t			num_times_philo_must_eat;
	size_t			initial_time_ms;
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
