#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>

typedef struct philo_args
{
	pthread_mutex_t *forks;
	int num_forks;
	int id;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_meals;
	pthread_mutex_t *print_lock;
	int *meal_count;
	pthread_mutex_t *meal_count_lock;
	struct timeval start_time; // Add the start_time member
} philo_args;

void *philosopher(void *args);

#endif
