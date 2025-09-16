/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:44:43 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/16 12:45:35 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "data.h"
#include "utils.h"

void	init(t_data *data, char **argv)
{
	data->num_philo = str_to_num(argv[1]);
	data->time_to_die_ms = str_to_num(argv[2]);
	data->time_to_eat_ms = str_to_num(argv[3]);
	data->time_to_sleep_ms = str_to_num(argv[4]);
	data->num_times_philo_must_eat = str_to_num(argv[5]);
}
