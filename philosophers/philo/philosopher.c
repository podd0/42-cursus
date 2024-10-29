/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:19:52 by apuddu            #+#    #+#             */
/*   Updated: 2024/10/29 19:42:36 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// being nice helps in balancing the load when n is odd
void	think(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->mut_death);
	check_dead(philo);
	printf("%ld %d is thinking\n", ft_time(), philo->id);
	pthread_mutex_unlock(&philo->ctx->mut_death);
	if ((philo->ctx->n & 1) && philo->ctx->time_sleep < philo->ctx->time_eat
		+ 10)
		my_sleep(philo->ctx->time_eat - philo->ctx->time_sleep + 10, philo);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->mut_death);
	check_dead(philo);
	printf("%ld %d is sleeping\n", ft_time(), philo->id);
	pthread_mutex_unlock(&philo->ctx->mut_death);
	my_sleep(philo->ctx->time_sleep, philo);
}

void	eat(t_philo *philo)
{
	if (philo->id == 0)
	{
		take_fork(philo, philo->id);
		take_fork(philo, (philo->id + 1) % philo->ctx->n);
	}
	else
	{
		take_fork(philo, (philo->id + 1) % philo->ctx->n);
		take_fork(philo, philo->id);
	}
	philo->etod = ft_time() + philo->ctx->time_die;
	pthread_mutex_lock(&philo->ctx->mut_death);
	check_dead(philo);
	printf("%ld %d is eating\n", ft_time(), philo->id);
	pthread_mutex_unlock(&philo->ctx->mut_death);
	my_sleep(philo->ctx->time_eat, philo);
	drop_forks(philo);
}

int	*philosopher(t_philo *philo)
{
	int	eat_limit;

	eat_limit = philo->ctx->eat_limit;
	philo->etod = philo->ctx->time_die + ft_time();
	if (philo->id & 1)
	{
		my_sleep(philo->ctx->time_eat / 3, philo);
	}
	while (eat_limit != 0)
	{
		if (philo->ctx->end_simulation)
			return (0);
		eat(philo);
		philo_sleep(philo);
		think(philo);
		if (eat_limit != -1)
			eat_limit--;
	}
	return (NULL);
}
