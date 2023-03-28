#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "philo.h"

void pick_fork(pthread_mutex_t *forks, int id, pthread_mutex_t *print_lock)
{
	pthread_mutex_lock(&forks[id]);
	pthread_mutex_lock(print_lock);
	printf("%d has taken fork %d\n", id + 1, id + 1);
	pthread_mutex_unlock(print_lock);
}

void release_fork(pthread_mutex_t *forks, int id, pthread_mutex_t *print_lock)
{
	pthread_mutex_unlock(&forks[id]);
	pthread_mutex_lock(print_lock);
	printf("%d has released fork %d\n", id + 1, id + 1);
	pthread_mutex_unlock(print_lock);
}

void *philosopher(void *args)
{
	philo_args *pargs = (philo_args *)args;
	int i;
	int left_fork, right_fork;
	int num_forks = pargs->num_forks;
	int num_meals = pargs->num_meals;
	int *meal_count = pargs->meal_count;

	if (pargs->id % 2 == 0)
	{
		left_fork = pargs->id;
		right_fork = (pargs->id + 1) % num_forks;
	}
	else
	{
		left_fork = (pargs->id + 1) % num_forks;
		right_fork = pargs->id;
	}

	for (i = 0; num_meals < 0 || i < num_meals; i++)
	{
		pthread_mutex_lock(pargs->meal_count_lock);
		if (*meal_count >= num_meals && num_meals > 0)
		{
			pthread_mutex_unlock(pargs->meal_count_lock);
			break;
		}
		(*meal_count)++;
		pthread_mutex_unlock(pargs->meal_count_lock);

		pick_fork(pargs->forks, left_fork, pargs->print_lock);
		pick_fork(pargs->forks, right_fork, pargs->print_lock);

		pthread_mutex_lock(pargs->print_lock);
		printf("%d is eating\n", pargs->id + 1);
		pthread_mutex_unlock(pargs->print_lock);
		usleep(pargs->time_to_eat * 1000);

		release_fork(pargs->forks, left_fork, pargs->print_lock);
		release_fork(pargs->forks, right_fork, pargs->print_lock);

		pthread_mutex_lock(pargs->print_lock);
		printf("%d is sleeping\n", pargs->id + 1);
		pthread_mutex_unlock(pargs->print_lock);
		usleep(pargs->time_to_sleep * 1000);
	}

	return NULL;
}
