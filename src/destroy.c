/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:37:55 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/07 11:39:22 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdlib.h>

void	destroy(t_data *data)
{
	if (data->threads)
		free(data->threads);
	if (data->mutexes)
		free(data->mutexes);
	if (data->philo)
		free(data->philo);
	if (data->queue)
		free(data->queue);
	if (data)
		free(data);
}
