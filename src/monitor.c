/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:59:44 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/02 10:17:01 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "end.h"
#include "monitor.h"
#include "print.h"
#include "time.h"

static bool	is_philo_starved(size_t	curr_time, t_data *data, t_philo philo);

void	*monitor(void *arg)
{
	t_data *data;
	size_t	i;
	size_t	curr_time;

	data = (t_data *)arg;
	while (1)
	{
		curr_time = get_curr_time(data);
		i = 0;
		while (i < data->num_philo)
		{
			if (is_philo_starved(curr_time, data, data->philo[i]) == true)
			{
				enable_end(data);
				print_log(&(data->philo[i]), DIE);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

static bool	is_philo_starved(size_t	curr_time, t_data *data, t_philo philo)
{
		pthread_mutex_lock(&data->last_meal_mutex);
		if (curr_time - philo.time_last_meal_ms > data->time_to_die_ms)
		{
			pthread_mutex_unlock(&data->last_meal_mutex);
			return (true);
		}
		else
		{
			pthread_mutex_unlock(&data->last_meal_mutex);
			return (false);
		}
}
