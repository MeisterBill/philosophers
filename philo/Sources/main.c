#include "../Includes/philo.h"

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
	return (0);
}
