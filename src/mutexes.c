/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:59:28 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/08 15:26:40 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "end.h"
#include "data.h"
#include "mutexes.h"
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
	pthread_mutex_init(&data->num_philo_fed_mutex, NULL);
	pthread_mutex_init(&data->start_mutex, NULL);
	pthread_mutex_init(&data->end_mutex, NULL);
}

void	destroy_mutexes(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->mutexes[i]);
		pthread_mutex_destroy(&data->philo[i].last_meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->log_mutex);
	pthread_mutex_destroy(&data->num_philo_fed_mutex);
	pthread_mutex_destroy(&data->start_mutex);
	pthread_mutex_destroy(&data->end_mutex);
}

void	lock_mutexes_asymettrically(t_philo *philo)
{
	if (philo->id % 2 == 0)
		lock_mutexes(philo, philo->left, philo->right);
	else
		lock_mutexes(philo, philo->right, philo->left);
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
