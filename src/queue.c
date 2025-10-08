/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:31:26 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/08 15:41:01 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	init_queue(t_data *data)
{
	size_t	queue_len;
	size_t	i;

	len = data->num_philo / 2;
	data->queue = malloc(sizeof(size_t) * len);
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
		data->queue[i] = i * 2;
		i++;
	}
}
