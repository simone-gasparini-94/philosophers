#ifndef DATA_H
# define DATA_H

# include <stddef.h>

typedef struct s_data
{
	size_t	num_philo;
	size_t	time_to_die_ms;
	size_t	time_to_eat_ms;
	size_t	time_to_sleep_ms;
	size_t	num_times_philo_must_eat;
}	t_data;

#endif
