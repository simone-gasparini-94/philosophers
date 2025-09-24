/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:34:34 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/24 13:22:00 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "data.h"
#include "print.h"
#include "time.h"
#include "mutexes.h"

static void	eat(t_philo *philo);

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		lock_mutexes(philo, philo->left, philo->right);
	else
		lock_mutexes(philo, philo->right, philo->left);
	eat(philo);
	unlock_mutexes(philo);
	return (NULL);
}

static void	eat(t_philo *philo)
{
	print_log(philo, EAT);
	usleep(philo->data->time_to_eat_ms * 1000);
}

