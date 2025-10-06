/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:42:21 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/06 13:23:21 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "args.h"
#include "data.h"
#include "init.h"
#include "mutexes.h"
#include "threads.h"

int	main(int argc, char *argv[])
{
	t_data *data;

	check_args(argc, argv);
	data = init(argv);
	init_mutexes(data);
	create_threads(data);
	join_threads(data);
	printf("num philo fed: %zu\n", data->num_philo_fed);
	for (size_t i = 0; i < data->num_philo; i++)
		printf("%zu num meals: %zu\n", data->philo[i].id, data->philo[i].num_meals);
	destroy_mutexes(data);
	return (0);
}
