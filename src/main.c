#include <stdio.h>
#include <pthread.h>
#include "args.h"
#include "data.h"
#include "init.h"

int	main(int argc, char *argv[])
{
	t_data data;

	check_args(argc, argv);
	init(&data, argv);
	return (0);
}
