/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:26:32 by apuddu            #+#    #+#             */
/*   Updated: 2024/10/29 19:30:48 by apuddu           ###   ########.fr       */
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
	int	i;

	ctx->n = ft_atoi(argv[1]);
	ctx->time_die = ft_atoi(argv[2]);
	ctx->time_eat = ft_atoi(argv[3]);
	ctx->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ctx->eat_limit = ft_atoi(argv[5]);
	else
		ctx->eat_limit = -1;
	ctx->forks = malloc(sizeof(int) * ctx->n);
	memset(ctx->forks, 0, sizeof(int) * ctx->n);
	ctx->mut = malloc(ctx->n * sizeof(pthread_mutex_t));
	i = 0;
	while (i < ctx->n)
	{
		pthread_mutex_init(ctx->mut + i, NULL);
		i++;
	}
	pthread_mutex_init(&ctx->mut_death, NULL);

	ctx->end_simulation = 0;
}

void	multi_free(void *a, void *b, void *c, void *d)
{
	free(a);
	free(b);
	free(c);
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
			multi_free(threads, args, ctx.mut, ctx.forks);
		}
		i++;
	}
	i = 0;
	while (i < ctx.n)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	multi_free(threads, args, ctx.mut, ctx.forks);
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
