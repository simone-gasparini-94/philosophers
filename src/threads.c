/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:38:23 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/06 15:06:19 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "data.h"
#include "monitor.h"
#include "routine.h"

void	create_threads(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&(data->threads[i]), NULL,
					routine, &(data->philo[i])) != 0)
		{
			perror("pthread_create");
			free(data->threads);
			free(data->philo);
			free(data);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_create(&data->monitor_thread, NULL, monitor, data) != 0)
	{
		perror("pthread_create");
		free(data->threads);
		free(data->philo);
		free(data);
		exit (EXIT_FAILURE);
	}
}

void	join_threads(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_join(data->threads[i], NULL) != 0)
		{
			perror("pthread_join");
			free(data->threads);
			free(data->philo);
			free(data);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_join(data->monitor_thread, NULL) != 0)
	{
		perror("pthread_join");
		free(data->threads);
		free(data->philo);
		free(data);
		exit (EXIT_FAILURE);
	}
}
