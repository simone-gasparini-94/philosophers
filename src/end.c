/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:49:24 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/01 13:26:35 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdio.h>

void	enable_end(t_data *data)
{
	pthread_mutex_lock(&data->end_mutex);
	data->end = true;
	pthread_mutex_unlock(&data->end_mutex);
}

bool	is_flag_enabled(t_data *data)
{
	bool	flag;

	flag = false;
	pthread_mutex_lock(&data->end_mutex);
	if (data->end == true)
		flag = true;
	pthread_mutex_unlock(&data->end_mutex);
	return (flag);
}
