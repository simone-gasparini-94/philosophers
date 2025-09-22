/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:44:43 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/22 16:22:58 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "utils.h"

static void init_threads(t_data *data);
static void	init_philo(t_data *data);

void	init(t_data *data, char **argv)
{
	data->num_philo = str_to_num(argv[1]);
	data->time_to_die_ms = str_to_num(argv[2]);
	data->time_to_eat_ms = str_to_num(argv[3]);
	data->time_to_sleep_ms = str_to_num(argv[4]);
	data->num_times_philo_must_eat = str_to_num(argv[5]);
	data->threads = malloc(sizeof(pthread_t) * data->num_philo);
	init_threads(data);
	init_philo(data);
}

static void init_threads(t_data *data)
{
	data->threads = malloc(sizeof(pthread_t) * data->num_philo);
	if (data->threads == NULL)
	{
		perror("malloc");
		exit (EXIT_FAILURE);
	}
}

static void	init_philo(t_data *data)
{
	size_t	i;

	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (data->philo == NULL)
	{
		free(data->threads);
		perror("malloc");
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].id = i;
		data->philo[i].data = data;
		i++;
	}
}
