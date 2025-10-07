/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:09:33 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/07 11:09:40 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

typedef struct s_data	t_data;

void	create_threads(t_data *data);
void	join_threads(t_data *data);

#endif
