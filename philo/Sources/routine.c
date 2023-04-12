/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:44:07 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/12 17:50:12 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

static int	get_right_fork(t_philo *philo)
{
	if (philo->id == 0)
		return (philo->data->nb_philo - 1);
	else
		return (philo->id - 1);
}

static int	eat(t_philo *philo)
{
	int	right_fork;

	right_fork = get_right_fork(philo);
	pthread_mutex_lock(&philo->data->forks[right_fork]);
	lock_and_print("has taken a fork", philo->id, philo->data, \
		philo->data->start_time);
	pthread_mutex_lock(&philo->data->forks[philo->id]);
	lock_and_print("has taken a fork", philo->id, philo->data, \
		philo->data->start_time);
	update_eat_time(philo);
	philo->count_eat--;
	lock_and_print("is eating", philo->id, philo->data, \
		philo->data->start_time);
	wait_sleepeat(philo->data->time_eat);
	pthread_mutex_unlock(&philo->data->forks[right_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->id]);
	return (1);
}

void	*routine(void *curr_philo)
{
	t_philo	*philo;

	philo = curr_philo;
	if (philo->id % 2 == 0)
		wait_sleepeat(philo->data->time_eat);
	while (!check_if_dead(philo->data) && philo->count_eat != 0)
	{
		lock_and_print("is thinking", philo->id, philo->data, \
			philo->data->start_time);
		eat(philo);
		lock_and_print("is sleeping", philo->id, philo->data, \
			philo->data->start_time);
		wait_sleepeat(philo->data->time_sleep);
	}
	return (NULL);
}
