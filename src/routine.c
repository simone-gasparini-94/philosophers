/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:34:34 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/01 14:21:54 by sgaspari         ###   ########.fr       */
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

static int	philo_eat(t_philo *philo);
static int	philo_sleep(t_philo *philo);
static int	philo_think(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (is_flag_enabled(philo->data) == true)
			break ;
		if (lock_mutexes_asymettrically(philo) == 1)
			break ;
		if (philo_eat(philo) == 1)
		{
			unlock_mutexes(philo);
			break ;
		}
		unlock_mutexes(philo);
		if (philo_sleep(philo) == 1)
			break ;
		if (philo_think(philo) == 1)
			break ;
	}
	return (NULL);
}

static int	philo_eat(t_philo *philo)
{
	print_log(philo, EAT);
	if (philo->data->num_meals_active == true)
		update_meals_counter(philo);
	update_time_last_meal(philo);
	usleep(philo->data->time_to_eat_ms * 1000);
	if (is_flag_enabled(philo->data) == true)
		return (1);
	return (0);
}

static int	philo_sleep(t_philo *philo)
{
	print_log(philo, SLEEP);
	usleep(philo->data->time_to_sleep_ms * 1000);
	if (is_flag_enabled(philo->data) == true)
		return (1);
	return (0);
}

static int	philo_think(t_philo *philo)
{
	print_log(philo, THINK);
	if (is_flag_enabled(philo->data) == true)
		return (1);
	return (0);
}
