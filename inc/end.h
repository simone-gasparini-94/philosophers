/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:31:12 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/07 11:10:33 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef END_H 
# define END_H

# include <stdbool.h>

typedef struct s_data	t_data;

void	enable_end(t_data *data);
bool	is_flag_enabled(t_data *data);

#endif
