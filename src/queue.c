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

#include <stdbool.h>
#include "data.h"

void	init_queue(t_data *data)
{
	size_t	queue_len;
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
	while (i < queue_len)
	{
		data->queue[i].id = i * 2;
		data->queue[i].eat = false;
		i++;
	}
}

bool	is_philo_in_queue(t_philo *philo)
{
	size_t	i;

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
	return (false);
}

bool	is_queue_fed(t_philo *philo)
{

}

void	update_queue(

