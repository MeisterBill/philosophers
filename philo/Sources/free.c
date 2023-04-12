/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:28:11 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/12 18:16:04 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

void	free_pf(t_data *data)
{
	free(data->philo);
	free(data->forks);
}

int	wait_for_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].thread, NULL))
			return (1);
		i++;
	}
	return (0);
}
