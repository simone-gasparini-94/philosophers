/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:36:43 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/15 10:36:45 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

void	init_queue(t_data *data);
void	shift_queue(t_data *data);
bool	is_philo_in_queue(t_philo *philo);
bool	is_queue_fed(t_data *data);

#endif
