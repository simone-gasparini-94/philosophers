/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:42:21 by sgaspari          #+#    #+#             */
/*   Updated: 2025/10/06 14:03:09 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include "args.h"
#include "data.h"
#include "init.h"
#include "mutexes.h"
#include "threads.h"

int	main(int argc, char *argv[])
{
	t_data *data;

	check_args(argc, argv);
	data = init(argv);
	init_mutexes(data);
	create_threads(data);
	join_threads(data);
	destroy_mutexes(data);
	return (0);
}
