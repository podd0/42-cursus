/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:48:26 by apuddu            #+#    #+#             */
/*   Updated: 2024/11/12 17:18:14 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	take_fork(t_philo *philo, int fork)
{
	while (1)
	{
		pthread_mutex_lock(philo->ctx->mut + fork);
		if (philo->ctx->forks[fork] == 0)
		{
			philo->ctx->forks[fork] = 1;
			pthread_mutex_unlock(philo->ctx->mut + fork);
			break ;
		}
		pthread_mutex_unlock(philo->ctx->mut + fork);
		if (my_sleep(1, philo))
			return (1);
	}
	pthread_mutex_lock(&philo->ctx->mut_death);
	if (check_dead(philo))
		return (1);
	printf("%ld %d has taken a fork\n", ft_time(), philo->id);
	pthread_mutex_unlock(&philo->ctx->mut_death);
	return (0);
}

void	drop_forks(t_philo *philo)
{
	int	f2;

	f2 = (philo->id + 1) % philo->ctx->n;
	pthread_mutex_lock(philo->ctx->mut + philo->id);
	philo->ctx->forks[philo->id] = 0;
	pthread_mutex_unlock(philo->ctx->mut + philo->id);
	pthread_mutex_lock(philo->ctx->mut + f2);
	philo->ctx->forks[f2] = 0;
	pthread_mutex_unlock(philo->ctx->mut + f2);
}
