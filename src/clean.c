/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:07:17 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/25 11:11:06 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "clean.h"

void	clean(data)
{
	if (data->threads != NULL)
		free(data->threads);
	if (data->mutexes != NULL)
		free(data->mutexes);
	if (data->philo != NULL)
		free(data->philo);
	if (data != NULL)
		free(data);
}
