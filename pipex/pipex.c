/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 01:51:11 by apuddu            #+#    #+#             */
/*   Updated: 2024/09/10 18:03:12 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>
#include <pipex.h>

void	reader(char **argv, char **environ)
{
	int			outp;
	char		**splitted;

	outp = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	dup2(outp, 1);
	splitted = ft_split(argv[3], ' ');
	execve(find_exec(splitted[0], get_path()), splitted, environ);
}

void	writer(char **argv, char **environ)
{
	int			inp;
	char		**splitted;

	inp = open(argv[1], O_RDONLY);
	dup2(inp, 0);
	splitted = ft_split(argv[2], ' ');
	execve(find_exec(splitted[0], get_path()), splitted, environ);
}

int	main(int argc, char **argv, char **env)
{
	int	pipe_fd[2];
	int	fork_res;

	if (argc != 5)
	{
		return (0);
	}
	if (pipe(pipe_fd))
		return (1);
	fork_res = fork();
	if (fork_res == -1)
		return (1);
	if (fork_res != 0)
	{
		dup2(pipe_fd[0], 0);
		close(pipe_fd[1]);
		reader(argv, env);
	}
	else
	{
		dup2(pipe_fd[1], 1);
		close(pipe_fd[0]);
		writer(argv, env);
	}
}
