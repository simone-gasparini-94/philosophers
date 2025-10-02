/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:59:28 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/02 10:11:13 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
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
	pthread_mutex_init(&data->last_meal_mutex, NULL);
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
	pthread_mutex_destroy(&data->last_meal_mutex);
	pthread_mutex_destroy(&data->end_mutex);
}

int		lock_mutexes_asymettrically(t_philo *philo)
{
		if (philo->id % 2 == 0)
		{
			if (lock_mutexes(philo, philo->left, philo->right) == 1)
				return (1);
		}
		else
		{
			if (lock_mutexes(philo, philo->right, philo->left) == 1)
				return (1);
		}
		return (0);
}

int		lock_mutexes(t_philo *philo,
		pthread_mutex_t *first, pthread_mutex_t *second)
{
	pthread_mutex_lock(first);
	print_log(philo, FORK);
	if (is_flag_enabled(philo->data) == true)
	{
		pthread_mutex_unlock(first);
		return (1);
	}
	pthread_mutex_lock(second);
	print_log(philo, FORK);
	return (0);
}

void	unlock_mutexes(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}
