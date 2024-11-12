/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:26:32 by apuddu            #+#    #+#             */
/*   Updated: 2024/11/12 20:42:01 by apuddu           ###   ########.fr       */
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

void	closeall(int *pid, int n)
{
	while (n--)
		kill(pid[n], SIGKILL);
	free(pid);
}

void	waitall(int *pids, int n)
{
	int	num;
	int	status;

	num = n;
	while (num--)
	{
		if (waitpid(-1, &status, 0) == -1)
		{
			closeall(pids, n);
			return ;
		}
		if ((((status) & 0xff00) >> 8) == 1)
		{
			closeall(pids, n);
			return ;
		}
	}
	closeall(pids, n);
}

void	core(t_ctx ctx)
{
	int		i;
	int		*pid;
	t_philo	philo;

	pid = malloc(ctx.n * sizeof(int));
	i = 0;
	while (i < ctx.n)
	{
		philo = (t_philo){&ctx, i, 0};
		pid[i] = fork();
		if (pid[i] < 0)
		{
			sem_wait(ctx.write_lock);
			printf("Error: fork\n");
			closeall(pid, i);
			return ;
		}
		else if (pid[i] == 0)
		{
			free(pid);
			philosopher(&philo);
		}
		i++;
	}
	waitall(pid, ctx.n);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (!check_args(argc, argv))
		return (0);
	ctx_init(&ctx, argc, argv);
	core(ctx);
	if (sem_unlink("/sem") != 0 && errno != ENOENT)
	{
		printf("error : sem unlink\n");
		exit(1);
	}
	if (sem_unlink("/wr") != 0 && errno != ENOENT)
	{
		printf("error : sem open\n");
		exit(1);
	}
}
