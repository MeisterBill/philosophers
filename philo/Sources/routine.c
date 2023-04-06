/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:44:07 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/05 14:19:17 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

int	get_right_fork(t_philo *philo)
{
	if (philo->id == 0)
		return (philo->data->nb_philo - 1);
	else
		return (philo->id - 1);
}

void	eat(t_philo *philo)
{
	int	right_fork;

	right_fork = get_right_fork(philo);
	pthread_mutex_lock(&philo->data->forks[right_fork]);
	lock_and_print("has picked up a fork.", philo->id, philo->data, \
		time_since_start(philo->data->start_time));
	pthread_mutex_lock(&philo->data->forks[philo->id]);
	lock_and_print("has picked up a fork.", philo->id, philo->data,
		time_since_start(philo->data->start_time));
	
}

void	*routine(void *curr_philo)
{
	t_philo	*philo;

	philo = curr_philo;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_eat * 1000);
	while (!check_if_dead(philo->data) && philo->count_eat != 0)
	{
		lock_and_print("is thinking.", philo->id, philo->data, \
			time_since_start(philo->data->start_time));
		//eat(philo);
		lock_and_print("is sleeping.", philo->id, philo->data, \
			time_since_start(philo->data->start_time));
		//waitsleepeat(philo->data->time_sleep);
	}
	return (NULL);
}
