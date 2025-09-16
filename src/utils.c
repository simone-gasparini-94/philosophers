/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:35:35 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/16 13:35:03 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>

size_t str_to_num(char *s)
{
	size_t	num;
	size_t	i;

	num = 0;
	if (s == NULL)
		return (num);
	i = 0;
	while (s[i] != '\0')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
	}
	return (num);
}
