/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:53:11 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/02 10:03:54 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "data.h"
#include "time.h"

void	print_log(t_philo *philo, t_log log)
{
	pthread_mutex_lock(&(philo->data->log_mutex));
	if (log == FORK)
		printf("%zu %zu has taken a fork\n",
				get_curr_time(philo->data), philo->id);
	if (log == EAT)
		printf("%zu %zu is eating\n",
				get_curr_time(philo->data), philo->id);
	if (log == SLEEP)
		printf("%zu %zu is sleeping\n",
				get_curr_time(philo->data), philo->id);
	if (log == THINK)
		printf("%zu %zu is thinking\n",
				get_curr_time(philo->data), philo->id);
	if (log == DIE)
	{
		printf("%zu %zu died\n",
				get_curr_time(philo->data), philo->id);
		printf("his last meal was at %zu\n", philo->time_last_meal_ms);
	}
	pthread_mutex_unlock(&(philo->data->log_mutex));
}
