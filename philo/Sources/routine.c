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

void	*routine(void *curr_philo)
{
	t_philo	*philo;

	philo = curr_philo;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_eat * 1000);
	while (!check_if_dead(philo->data) && philo->count_eat != 0)
	{
		lock_and_print("is thinking", philo->id, philo->data, \
			time_since_start(philo->data->start_time));
		//ft_eat(philo);
		lock_and_print("is sleeping", philo->id, philo->data, \
			time_since_start(philo->data->start_time));
		//ft_sleepeat(philo->data->time_sleep);
	}
	return (NULL);
}
