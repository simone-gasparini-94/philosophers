/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:34:39 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/22 17:34:41 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool	is_number(char *s);

void	check_args(int argc, char **argv)
{
	size_t	i;

	if (argc != 5 && argc != 6)
	{
		fprintf(stderr, "Error: Expected 4-5 arguments, got %d\n", argc - 1);
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < (size_t)argc)
	{
		if (is_number(argv[i]) == false)
		{
			fprintf(stderr, "Error: '%s' is not a valid number\n", argv[i]);
			fprintf(stderr, "All arguments must be positive integers\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static bool	is_number(char *s)
{
	size_t	i;

	if (s == NULL)
		return (false);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
