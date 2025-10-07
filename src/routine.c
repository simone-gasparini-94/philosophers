/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:34:34 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/07 11:05:09 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "data.h"
#include "end.h"
#include "meals.h"
#include "print.h"
#include "time.h"
#include "mutexes.h"

#define STEPS 50

static void	handle_one_philo(t_philo *philo);
static void	philo_eat(t_philo *philo);
static void	philo_sleep(t_philo *philo);
static void	philo_think(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (is_flag_enabled(philo->data) == false)
	{
		if (philo->data->num_philo == 1)
		{
			handle_one_philo(philo);
			break ;
		}
		lock_mutexes_asymettrically(philo);
		philo_eat(philo);
		unlock_mutexes(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_log(philo, FORK);
	while (1)
	{
		if (is_flag_enabled(philo->data) == true)
		{
			pthread_mutex_unlock(philo->left);
			return ;
		}
		usleep(1000);
	}
}

static void	philo_eat(t_philo *philo)
{
	print_log(philo, EAT);
	update_time_last_meal(philo);
	if (philo->data->num_meals_active == true)
		update_meals_counter(philo);
	usleep(philo->data->time_to_eat_ms * 1000 / STEPS);
	update_time_last_meal(philo);
	usleep(philo->data->time_to_eat_ms * 1000 / STEPS * (STEPS - 1));
}

static void	philo_sleep(t_philo *philo)
{
	print_log(philo, SLEEP);
	usleep(philo->data->time_to_sleep_ms * 1000);
}

static void	philo_think(t_philo *philo)
{
	print_log(philo, THINK);
}
