/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:26:32 by apuddu            #+#    #+#             */
/*   Updated: 2024/10/30 16:15:20 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("wrong number of parameters\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_num(argv[i]))
		{
			printf("all arguments must be numeric\n");
			return (0);
		}
		i++;
	}
	return (1);
}

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
	ctx->end_simulation = 0;
	if (sem_unlink("/sem") != 0 && errno != ENOENT)
	{
		printf("error : sem open\n");
		exit(1);
	}
	ctx->sem = sem_open("/sem", O_CREAT, 0644, ctx->n);
	if (sem_unlink("/wr") != 0 && errno != ENOENT)
	{
		printf("error : sem open\n");
		exit(1);
	}
	ctx->write_lock = sem_open("/wr", O_CREAT, 0644, 1);
}

void	multi_free(void *a, void *b, void *c, void *d)
{
	if (a)
		free(a);
	if (b)
		free(b);
	if (c)
		free(c);
	if (d)
		free(d);
}

void	core(t_ctx ctx, pthread_t *threads, t_philo *args)
{
	int	i;

	i = 0;
	while (i < ctx.n)
	{
		args[i] = (t_philo){&ctx, i, 0};
		if (pthread_create(threads + i, NULL, (void *(*)(void *))philosopher,
			args + i) < 0)
		{
			printf("Error: pthread_create\n");
			multi_free(threads, args, NULL, NULL);
		}
		i++;
	}
	i = 0;
	while (i < ctx.n)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	multi_free(threads, args, NULL, NULL);
	sem_unlink("/sem");
	sem_unlink("/wr");
}

int	main(int argc, char **argv)
{
	t_ctx		ctx;
	pthread_t	*threads;
	t_philo		*args;

	if (!check_args(argc, argv))
		return (0);
	ctx_init(&ctx, argc, argv);
	threads = malloc(sizeof(pthread_t) * ctx.n);
	args = malloc(sizeof(t_philo) * ctx.n);
	core(ctx, threads, args);
	
}
