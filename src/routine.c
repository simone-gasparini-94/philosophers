/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:34:34 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/22 17:36:37 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include "data.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Philosopher id is %zu\n", (size_t) philo->id);
	return (NULL);
}
