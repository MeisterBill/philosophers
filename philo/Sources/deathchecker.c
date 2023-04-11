/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deathchecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:22:16 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/06 22:28:31 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

static void	death_checker(t_data *data)
{
	int		i;
	long	time_since_eat;

	i = 0;
	while (i < data->nb_philo)
	{
		time_since_eat = get_time() - get_lasteat_time(&data->philo[i]);
		if (time_since_eat > data->time_die)
		{
			kill_philo(data);
			if (data->philo[i].count_eat != 0)
				printf("%ld Philosopher %d has died.\n", \
					time_since_start(data->start_time), data->philo[i].id);
			return ;
		}
		i++;
	}
}

void	perma_death_checker(t_data *data)
{
	while (!check_if_dead(data))
	{
		death_checker(data);
		usleep(1000);
	}
	free_pf(data);
}
