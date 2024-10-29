/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:27:19 by apuddu            #+#    #+#             */
/*   Updated: 2024/10/29 09:31:23 by apuddu           ###   ########.fr       */
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
# include <semaphore.h>
# include <fcntl.h>

typedef struct s_ctx
{
	int		n;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		eat_limit;
	int		end_simulation;
	sem_t	*sem;
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
void	my_sleep(long time, t_philo *philo);
void	check_dead(t_philo *philo);

void	drop_forks(t_philo *philo);
void	take_fork(t_philo *philo);
int		*philosopher(t_philo *philo);
#endif