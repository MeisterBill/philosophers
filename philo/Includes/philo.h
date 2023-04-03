/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:44:19 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/03 19:34:57 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		thread;
	int				id;
	long			time_last_eat;
	int				count_eat;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				is_dead;
	long			start_time;
	pthread_mutex_t	status;
	pthread_mutex_t	eat_time;
	pthread_mutex_t	*forks;
}	t_data;

//  ATOI
int		ft_isdigit(int i);
int		ft_atoi(char *str, int *nb);

//  TIMING
long	get_time(void);

//  FREE
void	free_philo_and_forks(t_data *data);

//  PHILO
void	*full_cycle(void *curr_philo);

#endif
