/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:48:26 by apuddu            #+#    #+#             */
/*   Updated: 2024/11/12 20:25:42 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	take_fork(t_philo *philo)
{
	sem_wait(philo->ctx->sem);
	sem_wait(philo->ctx->write_lock);
	check_dead(philo);
	printf("%ld %d has taken a fork\n", ft_time(), philo->id);
	sem_post(philo->ctx->write_lock);
}

void	drop_forks(t_philo *philo)
{
	sem_post(philo->ctx->sem);
	sem_post(philo->ctx->sem);
}
