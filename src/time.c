/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:31:03 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/06 18:16:54 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include "data.h"

size_t	get_initial_time(void)
{
	struct timeval tv;
	size_t	time_ms;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return (0);
	}
	time_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_ms);
}

size_t	get_curr_time(t_data *data)
{
	struct timeval tv;
	size_t	time_ms;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return (0);
	}
	time_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - data->initial_time_ms;
	return (time_ms);
}

void	update_time_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&(philo->last_meal_mutex));
	philo->time_last_meal_ms = get_curr_time(philo->data);
	pthread_mutex_unlock(&(philo->last_meal_mutex));
}
