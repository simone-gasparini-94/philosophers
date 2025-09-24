/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:31:03 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/24 12:25:22 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include "data.h"

size_t	get_initial_time(void)
{
	struct timeval tv;
	size_t	time_ms;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return (0);
	}
	time_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_ms);
}

size_t	get_current_time(t_data *data)
{
	struct timeval tv;
	size_t	time_ms;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday");
		return (0);
	}
	time_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - data->initial_time_ms;
	return (time_ms);
}
