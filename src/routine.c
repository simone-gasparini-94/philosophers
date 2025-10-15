/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:34:34 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/15 16:10:03 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "data.h"
#include "end.h"
#include "queue.h"
#include "meals.h"
#include "print.h"
#include "routine.h"
#include "time.h"
#include "mutexes.h"

static void	lock_and_eat(t_philo *philo);
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
		if (is_philo_in_queue(philo) == true)
			lock_and_eat(philo);
		else
		{
			continue ;
		}
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

static void	lock_and_eat(t_philo *philo)
{
	lock_mutexes_asymettrically(philo);
	philo_eat(philo);
	unlock_mutexes(philo);
}

static void	philo_eat(t_philo *philo)
{
	print_log(philo, EAT);
	if (philo->data->num_meals_active == true)
		update_meals_counter(philo);
	update_time_last_meal(philo);
	usleep(philo->data->time_to_eat_ms * 1000);
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
