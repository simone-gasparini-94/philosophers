/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:34:34 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/01 13:33:20 by sgaspari         ###   ########.fr       */
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

static void	philo_eat(t_philo *philo);
static void	philo_sleep(t_philo *philo);
static void	philo_think(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (is_flag_enabled(philo->data) == true)
			break ;
		if (philo->id % 2 == 0)
			lock_mutexes(philo, philo->left, philo->right);
		else
			lock_mutexes(philo, philo->right, philo->left);
		philo_eat(philo);
		unlock_mutexes(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
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
