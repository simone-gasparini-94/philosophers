#ifndef THREADS_H
# define THREADS_H

typedef struct s_data t_data;

void	create_threads(t_data *data);
void	join_threads(t_data *data);

#endif
