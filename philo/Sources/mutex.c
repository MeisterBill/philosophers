/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:46:44 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/06 18:23:54 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

int	check_if_dead(t_data *data)
{
	int	dead;

	pthread_mutex_lock(&data->status);
	if (data->is_dead)
		dead = 1;
	else
		dead = 0;
	pthread_mutex_unlock(&data->status);
	return (dead);
}

/*
void	lock_and_print(char *str, int id, t_data *data, long timestamp)
{
	pthread_mutex_lock(&data->status);
	if (!data->is_dead)
		printf("%ld Philosopher %i %s\n", timestamp, id, str);
	pthread_mutex_unlock(&data->status);
}*/

void	lock_and_print(char *str, int id, t_data *data, long start_time)
{
	long	timestamp;

	pthread_mutex_lock(&data->status);
	if (!data->is_dead)
	{
		timestamp = time_since_start(start_time);
		printf("%ld Philosopher %i %s\n", timestamp, id, str);
	}
	pthread_mutex_unlock(&data->status);
}

void	update_eat_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_time);
	philo->time_last_eat = get_time();
	pthread_mutex_unlock(&philo->data->eat_time);
}
