/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:32:40 by apuddu            #+#    #+#             */
/*   Updated: 2024/10/29 19:50:16 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long	ft_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	die(t_philo *philo)
{
	if (philo->ctx->end_simulation)
	{
		pthread_mutex_unlock(&philo->ctx->mut_death);
		pthread_exit(NULL);
	}
	philo->ctx->end_simulation = 1;
	printf("%ld %d died\n", ft_time(), philo->id);
	pthread_mutex_unlock(&philo->ctx->mut_death);
	pthread_exit(NULL);
}

void	check_dead(t_philo *philo)
{
	if (philo->ctx->end_simulation == 1)
	{
		pthread_mutex_unlock(&philo->ctx->mut_death);
		pthread_exit(NULL);
	}	
	if (philo->etod < ft_time())
	{
		die(philo);
	}
}

void	my_sleep(long time, t_philo *philo)
{
	long	now;

	now = ft_time();
	if (now + time >= philo->etod)
	{
		time = (philo->etod - now) * 1000;
		usleep(time);

		pthread_mutex_lock(&philo->ctx->mut_death);
		die(philo);
		pthread_mutex_unlock(&philo->ctx->mut_death);
	}
	else
		usleep(time * 1000);
}
