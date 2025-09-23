/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:42:30 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/23 17:43:16 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEXES_H
# define MUTEXES_H

typedef struct s_data t_data;

void	init_mutexes(t_data *data);
void	destroy_mutexes(t_data *data);

#endif
