/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:24:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/01 11:58:59 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "monitor.h"

static void	update_fed_counter(t_data *data);

void	update_meals_counter(t_philo *philo)
{
	philo->num_meals++;
	if (philo->num_meals >= philo->data->num_times_philo_must_eat)
		update_fed_counter(philo->data);
}

static void	update_fed_counter(t_data *data)
{
	data->num_philo_fed++;
	if (data->num_philo_fed >= data->num_philo)
		enable_end(data);
}
