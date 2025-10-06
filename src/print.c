/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:53:11 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/06 16:59:27 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "data.h"
#include "end.h"
#include "time.h"

void	print_log(t_philo *philo, t_log log)
{
	size_t	curr_time;

	curr_time = get_curr_time(philo->data);
	pthread_mutex_lock(&(philo->data->log_mutex));
	if (log == DIE)
	{
		printf("%zu %zu died\n", curr_time, philo->id);
	}
	else if (is_flag_enabled(philo->data) == false)
	{
		if (log == FORK)
			printf("%zu %zu has taken a fork\n", curr_time, philo->id);
		else if (log == EAT)
			printf("%zu %zu is eating\n", curr_time, philo->id);
		else if (log == SLEEP)
			printf("%zu %zu is sleeping\n", curr_time, philo->id);
		else if (log == THINK)
			printf("%zu %zu is thinking\n", curr_time, philo->id);
	}
	pthread_mutex_unlock(&(philo->data->log_mutex));
}
