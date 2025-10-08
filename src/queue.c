/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:31:26 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/08 16:28:54 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "data.h"

void	init_queue(t_data *data)
{
	size_t	i;

	data->len_queue = data->num_philo / 2;
	data->queue = malloc(sizeof(t_queue) * data->len_queue);
	if (data->queue == NULL)
	{
		perror("malloc");
		free(data->threads);
		free(data->mutexes);
		free(data->philo);
		free(data);
	}
	i = 0;
	while (i < data->len_queue)
	{
		data->queue[i].id = i * 2;
		data->queue[i].eat = false;
		i++;
	}
}

bool	is_philo_in_queue(t_philo *philo)
{
	size_t	i;

	pthread_mutex_lock(&(philo->data->queue_mutex));
	i = 0;
	while (i < philo->data->len_queue)
	{
		if (philo->id == philo->data->queue[i].id)
		{
			philo->data->queue[i].eat = true;
			return (true);
		}
		i++;
	}
	pthread_mutex_unlock(&(philo->data->queue_mutex));
	return (false);
}
