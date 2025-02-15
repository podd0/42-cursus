/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:32:40 by apuddu            #+#    #+#             */
/*   Updated: 2024/11/12 19:58:03 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long	ft_time(void)
{
	static long		start = 0;
	struct timeval	tv;

	if (start == 0)
	{
		gettimeofday(&tv, NULL);
		start = (long)tv.tv_sec * 1000 + tv.tv_usec / 1000;
		return (0);
	}
	gettimeofday(&tv, NULL);
	return ((long)tv.tv_sec * 1000 + tv.tv_usec / 1000 - start);
}

void	die(t_philo *philo)
{
	printf("%ld %d died\n", ft_time(), philo->id);
	exit(1);
}

void	check_dead(t_philo *philo)
{
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
		sem_wait(philo->ctx->write_lock);
		die(philo);
		sem_post(philo->ctx->write_lock);
	}
	else
		usleep(time * 1000);
}
