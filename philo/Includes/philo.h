/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artvan-d <artvan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:44:19 by artvan-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:08:02 by artvan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
long	time_since_start(long start_time);
void	wait_sleepeat(int time);

//  FREE
void	free_pf(t_data *data);

//  PHILO
void	*routine(void *curr_philo);

//  MUTEX
int		check_if_dead(t_data *data);
void	lock_and_print(char *str, int id, t_data *data, long timestamp);
void	update_eat_time(t_philo *philo);

#endif
