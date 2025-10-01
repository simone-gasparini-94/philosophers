/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:59:28 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/01 12:22:47 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "data.h"
#include "print.h"

void	init_mutexes(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_init(&data->mutexes[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->log_mutex, NULL);
	pthread_mutex_init(&data->end_mutex, NULL);
}

void	destroy_mutexes(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->mutexes[i]);
		i++;
	}
	pthread_mutex_destroy(&data->log_mutex);
	pthread_mutex_destroy(&data->end_mutex);
}

void	lock_mutexes(t_philo *philo,
		pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_lock(first);
	print_log(philo, FORK);
	pthread_mutex_lock(second);
	print_log(philo, FORK);
}

void	unlock_mutexes(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}
