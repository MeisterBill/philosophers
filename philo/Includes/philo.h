#ifndef PHILO_H
#	define PHILO_H

#include <pthread.h>

typedef struct s_data
{
	int 	nb_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int 	must_eat;
	int		is_dead;
	long	start_time;
}	t_data;


#endif
