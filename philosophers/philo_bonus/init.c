/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:41:26 by apuddu            #+#    #+#             */
/*   Updated: 2024/11/12 20:42:32 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ctx_init(t_ctx *ctx, int argc, char **argv)
{
	ctx->n = ft_atoi(argv[1]);
	ctx->time_die = ft_atoi(argv[2]);
	ctx->time_eat = ft_atoi(argv[3]);
	ctx->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ctx->eat_limit = ft_atoi(argv[5]);
	else
		ctx->eat_limit = -1;
	if (sem_unlink("/sem") != 0 && errno != ENOENT)
	{
		printf("error : sem unlink\n");
		exit(1);
	}
	ctx->sem = sem_open("/sem", O_CREAT, 0644, ctx->n);
	if (sem_unlink("/wr") != 0 && errno != ENOENT)
	{
		printf("error : sem open\n");
		exit(1);
	}
	ctx->write_lock = sem_open("/wr", O_CREAT, 0644, 1);
	(void)ft_time();
}
