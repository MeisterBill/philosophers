/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:44:12 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:27:20 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

long	get_time(void)
{
	struct timeval	curr_time;

	gettimeofday(&curr_time, NULL);
	return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));
}

long	time_since_start(long start_time)
{
	return (get_time() - start_time);
}

void	wait_sleepeat(int time)
{
	long	start;
	long	elapsed;

	start = get_time();
	elapsed = 0;
	while (elapsed < time)
	{
		usleep(time * 1000);
		elapsed = get_time() - start;
	}
}

int	ft_isdigit(int i)
{
	if (i > 47 && i < 58)
		return (1);
	return (0);
}

int	ft_atoi(char *str, int *nb)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			*nb = (*nb * 10) + (str[i++] - '0');
		else
			return (1);
		if (*nb > 2147483647)
			return (1);
	}
	return (0);
}
