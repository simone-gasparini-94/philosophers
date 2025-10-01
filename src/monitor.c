/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:59:44 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/01 13:43:18 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "data.h"
#include "end.h"
#include "monitor.h"
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
		i = 0;
		while (i < data->num_philo)
		{
			curr_time = get_curr_time(data);
			if (is_philo_starved(curr_time, data, data->philo[i]) == true)
			{
				enable_end(data);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

static bool	is_philo_starved(size_t	curr_time, t_data *data, t_philo philo)
{
		if (curr_time - philo.time_last_meal_ms > data->time_to_die_ms)
			return (true);
		else
			return (false);
}
