/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:44:43 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/07 11:49:45 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "end.h"
#include "utils.h"
#include "time.h"

static void	parse_argv(t_data *data, char **argv);
static void	init_threads(t_data *data);
static void	init_mutexes(t_data *data);
static void	init_philo(t_data *data);

t_data	*init(char **argv)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(*data));
	if (data == NULL)
		exit (EXIT_FAILURE);
	data->end = false;
	data->num_philo_fed = 0;
	parse_argv(data, argv);
	data->philo = NULL;
	data->threads = NULL;
	data->mutexes = NULL;
	init_threads(data);
	init_mutexes(data);
	init_philo(data);
	data->initial_time_ms = get_initial_time();
	return (data);
}

static void	parse_argv(t_data *data, char **argv)
{
	data->num_philo = str_to_num(argv[1]);
	data->time_to_die_ms = str_to_num(argv[2]);
	data->time_to_eat_ms = str_to_num(argv[3]);
	data->time_to_sleep_ms = str_to_num(argv[4]);
	data->num_times_philo_must_eat = str_to_num(argv[5]);
	if (argv[5] == NULL)
		data->num_meals_active = false;
	else
	{
		data->num_meals_active = true;
		if (data->num_times_philo_must_eat == 0)
			enable_end(data);
	}
}

static void	init_threads(t_data *data)
{
	data->threads = malloc(sizeof(pthread_t) * data->num_philo);
	if (data->threads == NULL)
	{
		perror("malloc");
		free(data);
		exit (EXIT_FAILURE);
	}
}

static void	init_mutexes(t_data *data)
{
	data->mutexes = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (data->mutexes == NULL)
	{
		perror("malloc");
		free(data->threads);
		free(data);
		exit (EXIT_FAILURE);
	}
}

static void	init_philo(t_data *data)
{
	size_t	i;

	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	if (data->philo == NULL)
	{
		perror("malloc");
		free(data->threads);
		free(data->mutexes);
		free(data);
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].id = i;
		data->philo[i].num_meals = 0;
		data->philo[i].data = data;
		data->philo[i].left = &(data->mutexes[i]);
		data->philo[i].right = &(data->mutexes[(i + 1) % data->num_philo]);
		data->philo[i].time_last_meal_ms = 0;
		pthread_mutex_init(&data->philo[i].last_meal_mutex, NULL);
		i++;
	}
}
