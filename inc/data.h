/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:33:44 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/22 16:20:48 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <sys/types.h>
# include <pthread.h>

typedef struct s_data t_data;

typedef struct s_philo
{
	t_data		*data;
	size_t		id;
}	t_philo;

typedef struct s_data
{
	t_philo		*philo;
	pthread_t	*threads;
	size_t		num_philo;
	size_t		time_to_die_ms;
	size_t		time_to_eat_ms;
	size_t		time_to_sleep_ms;
	size_t		num_times_philo_must_eat;
}	t_data;

#endif
