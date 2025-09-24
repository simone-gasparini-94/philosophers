/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:42:30 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/24 12:48:23 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEXES_H
# define MUTEXES_H

# include <pthread.h>

typedef struct s_data t_data;
typedef struct s_philo t_philo;

void	init_mutexes(t_data *data);
void	destroy_mutexes(t_data *data);
void	lock_mutexes(t_philo *philo,
		pthread_mutex_t *first, pthread_mutex_t *second);

#endif
