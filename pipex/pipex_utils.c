/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:15:13 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/30 19:18:29 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <unistd.h>
#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>

static char	*path_join(char *p1, char *p2)
{
	int		len;
	char	*res;
	int		add_slash;

	len = 1 + ft_strlen(p1);
	add_slash = (p1[len - 2] != '/');
	len += add_slash;
	len += ft_strlen(p2);
	res = malloc(len);
	ft_strlcpy(res, p1, len);
	if (add_slash)
		ft_strlcat(res, "/", len);
	ft_strlcat(res, p2, len);
	return (res);
}

char	*find_exec(char *cmd, char **path)
{
	char	**it;
	char	*exec;

	if (cmd[0] == '.' || cmd[0] == '/')
		exec = cmd;
	else
	{
		it = path;
		while (*it)
		{
			exec = path_join(*it, cmd);
			if (!access(exec, F_OK | X_OK))
				break ;
			free(exec);
			it++;
		}
		if (!(*it))
			exec = NULL;
	}
	ft_split_free(path);
	return (exec);
}

char	**get_path(void)
{
	extern char	**environ;

	while (ft_strncmp(*environ, "PATH=", 5))
		environ++;
	return (ft_split((*environ) + 5, ':'));
}
