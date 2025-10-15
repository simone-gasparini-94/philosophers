/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:26:12 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/15 10:28:46 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include "data.h"
#include "end.h"
#include "print.h"

void	handle_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_log(philo, FORK);
	while (1)
	{
		if (is_flag_enabled(philo->data) == true)
		{
			pthread_mutex_unlock(philo->left);
			return ;
		}
		usleep(1000);
	}
}
