#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "philo.h"

int main(int argc, char *argv[])
{
	// Parse command line arguments
	if (argc < 5 || argc > 6)
	{
		printf("Usage: ./philo num_philosophers time_to_die time_to_eat time_to_sleep [num_meals]\n");
		return 1;
	}
	int num_philosophers = atoi(argv[1]);
	int time_to_die = atoi(argv[2]);
	int time_to_eat = atoi(argv[3]);
	int time_to_sleep = atoi(argv[4]);
	int num_meals = -1;
	if (argc == 6)
	{
		num_meals = atoi(argv[5]);
	}

	// Allocate memory for forks
	pthread_mutex_t *forks = malloc(sizeof(pthread_mutex_t) * num_philosophers);
	for (int i = 0; i < num_philosophers; i++)
	{
		pthread_mutex_init(&forks[i], NULL);
	}

	// Allocate memory for philosopher arguments
	philo_args *philosophers = malloc(sizeof(philo_args) * num_philosophers);

	// Allocate memory for meal count and its lock
	int *meal_count = malloc(sizeof(int));
	*meal_count = 0;
	pthread_mutex_t *meal_count_lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(meal_count_lock, NULL);

	// Allocate memory for print lock
	pthread_mutex_t *print_lock = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(print_lock, NULL);

	// Create philosopher threads
	pthread_t *threads = malloc(sizeof(pthread_t) * num_philosophers);
	for (int i = 0; i < num_philosophers; i++)
	{
		philosophers[i].forks = forks;
		philosophers[i].num_forks = num_philosophers;
		philosophers[i].id = i;
		philosophers[i].time_to_die = time_to_die;
		philosophers[i].time_to_eat = time_to_eat;
		philosophers[i].time_to_sleep = time_to_sleep;
		philosophers[i].num_meals = num_meals;
		philosophers[i].print_lock = print_lock;
		philosophers[i].meal_count = meal_count;
		philosophers[i].meal_count_lock = meal_count_lock;
		pthread_create(&threads[i], NULL, philosopher, (void *)&philosophers[i]);
	}

	// Wait for philosopher threads to finish
	for (int i = 0; i < num_philosophers; i++)
	{
		pthread_join(threads[i], NULL);
	}

	// Clean up resources
	for (int i = 0; i < num_philosophers; i++)
	{
		pthread_mutex_destroy(&forks[i]);
	}
	free(forks);
	free(philosophers);
	free(threads);
	free(meal_count_lock);
	free(meal_count);
	free(print_lock);

	return 0;
}
