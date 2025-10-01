/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:15:49 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/01 12:53:55 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include <sys/types.h>

typedef struct s_data t_data;
typedef struct s_philo t_philo;

size_t	get_initial_time(void);
size_t	get_curr_time(t_data *data);
void	update_time_last_meal(t_philo *philo);

#endif
