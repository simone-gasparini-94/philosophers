/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:59:28 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/23 17:45:55 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "data.h"

void	init_mutexes(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_init(&data->mutexes[i], NULL);
		i++;
	}
}

void	destroy_mutexes(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->mutexes[i]);
		i++;
	}
}
