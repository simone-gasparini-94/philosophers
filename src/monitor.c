/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:59:44 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/06 17:23:12 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "data.h"
#include "end.h"
#include "monitor.h"
#include "print.h"
#include "time.h"

static bool	is_philo_starved(t_data *data, t_philo *philo);

void	*monitor(void *arg)
{
	t_data *data;
	size_t	i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->num_philo)
		{
			if (is_philo_starved(data, &(data->philo[i])) == true)
			{
				enable_end(data);
				print_log(&(data->philo[i]), DIE);
				return (NULL);
			}
			i++;
		}
		if (is_flag_enabled(data) == true)
			break ;
	}
	return (NULL);
}

static bool	is_philo_starved(t_data *data, t_philo *philo)
{
	bool	starved;
	size_t	curr_time;

	pthread_mutex_lock(&philo->last_meal_mutex);
	curr_time = get_curr_time(data);
	starved = (curr_time - philo->time_last_meal_ms > data->time_to_die_ms);
	pthread_mutex_unlock(&philo->last_meal_mutex);
	return (starved);
}
