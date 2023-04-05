/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:46:44 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/05 14:12:56 by artvan-d         ###   ########.fr       */
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

void	lock_and_print(char *str, int id, t_data *data, long timestamp)
{
	pthread_mutex_lock(&data->status);
	if (!data->is_dead)
		printf("%ld Philosopher %i %s\n", timestamp, id, str);
	pthread_mutex_unlock(&data->status);
}
