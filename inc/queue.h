#ifndef QUEUE_H
# define QUEUE_H

void	init_queue(t_data *data);
void	shift_queue(t_data *data);
bool	is_philo_in_queue(t_philo *philo);
bool	is_queue_fed(t_philo *philo);

#endif
