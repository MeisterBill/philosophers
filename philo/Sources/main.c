/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:44:00 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/03 19:24:18 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/philo.h"

static int	malloc_init_pf(t_data *data)
{
	if (pthread_mutex_init(&data->status, NULL))
		return (1);
	if (pthread_mutex_init(&data->eat_time, NULL))
		return (1);
	data->philo = malloc(data->nb_philo * sizeof(t_philo));
	if (!data->philo)
		return (1);
	data->forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
	{
		free(data->philo);
		return (1);
	}
	return (0);
}

static	int	create_philos(t_data *data, int i)
{
	data->philo[i].id = i;
	data->philo[i].time_last_eat = get_time();
	data->philo[i].data = data;
	data->philo[i].count_eat = data->must_eat;
	if (pthread_create(&data->philo[i].thread, NULL, &full_cycle, \
	&data->philo[i]))
		return (1);
	return (0);
}

static	int	init_philo_forks(t_data *data)
{
	int	i;

	i = 0;
	if (malloc_init_pf(data))
		return (1);
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL))
		{
			free_pf(data);
			return (1);
		}
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (create_philos(data, i))
		{
			free_pf(data);
			return (1);
		}
		i++;
	}
	return (0);
}

static	int	argv_parsing(int ac, char **argv, t_data *data)
{
	data->nb_philo = 0;
	data->must_eat = 0;
	data->time_die = 0;
	data->time_eat = 0;
	data->time_sleep = 0;
	data->start_time = get_time();
	data->is_dead = 0;
	if (ft_atoi(argv[1], &data->nb_philo)
		|| ft_atoi(argv[2], &data->time_die)
		|| ft_atoi(argv[3], &data->time_eat)
		|| ft_atoi(argv[4], &data->time_sleep))
		return (1);
	if (data->nb_philo < 1)
		return (1);
	if (ac == 4)
	{
		if (ft_atoi(argv[5], &data->must_eat))
			return (1);
	}
	else
		data->must_eat = -1;
	return (0);
}

int	main(int ac, char **argv)
{
	t_data	data;

	if (ac > 6 || ac < 5)
	{
		printf("Number of arguments not valid.\n");
		return (1);
	}
	if (argv_parsing(ac, argv, &data))
	{
		printf("Argument(s) must be positive integers.\n");
		return (1);
	}
	if (init_philo_forks(&data))
	{
		printf("Some error msg.\n");
		return (1);
	}
	return (0);
}
