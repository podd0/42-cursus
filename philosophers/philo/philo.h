/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:27:19 by apuddu            #+#    #+#             */
/*   Updated: 2024/11/12 17:02:46 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_ctx
{
	int				n;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				eat_limit;
	int				*forks;
	pthread_mutex_t	*mut;
	pthread_mutex_t	mut_death;
	int				end_simulation;
}	t_ctx;

typedef struct s_philo
{
	t_ctx	*ctx;
	int		id;
	long	etod;
}	t_philo;

int		is_num(char *s);
int		ft_atoi(const char *s);
long	ft_time(void);
int		my_sleep(long time, t_philo *philo);
int		check_dead(t_philo *philo);

void	drop_forks(t_philo *philo);
int		take_fork(t_philo *philo, int fork);
int		*philosopher(t_philo *philo);
#endif