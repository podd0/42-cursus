/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:53:11 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/23 16:38:39 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <fdf.h>
#include <get_next_line.h>
#include <math.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <vector.h>

static void	split_free(char **split)
{
	char	**it;

	it = split;
	while (*it)
	{
		free(*it);
		it++;
	}
	free(split);
}

static unsigned int	from_hex(char *s)
{
	unsigned int	res;

	res = 0;
	while (ft_isdigit(*s) || ('a' <= *s && *s <= 'f'))
	{
		res *= 16;
		if (ft_isdigit(*s))
			res += *s - '0';
		else
			res += *s - 'a' + 10;
		s++;
	}
	return (res);
}

static t_parsed_line	from_line(char *s, int line_index)
{
	char			**splitted;
	int				col_index;
	t_parsed_line	res;
	char			*it;

	res.vecs = vvec_uninit(0);
	res.colors = vu_uninit(0);
	col_index = 0;
	if (s[ft_strlen(s) - 1] == '\n')
		s[ft_strlen(s) - 1] = '\0';
	splitted = ft_split(s, ' ');
	free(s);
	while (splitted[col_index])
	{
		it = splitted[col_index];
		vvec_push_back(res.vecs, (t_vec3){-line_index, -col_index,
			ft_atoi_advance(&it)});
		if (*it == ',' && it[1] == '0' && it[2] == 'x')
			vu_push_back(res.colors, from_hex(it + 3));
		else
			vu_push_back(res.colors, 0xffffff);
		col_index++;
	}
	split_free(splitted);
	return (res);
}

t_context	parse_file_decenter(char *filename)
{
	t_parsed_line	parsed_line;
	int				fd;
	char			*line;
	t_context		ctx;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	ctx.grid = grid_uninit(0);
	ctx.colors = vvu_uninit(0);
	line = get_next_line(fd);
	while (line)
	{
		parsed_line = from_line(line, ctx.grid->size);
		if (parsed_line.vecs->size == 0 || (ctx.grid->size
				&& parsed_line.vecs->size != grid_back(ctx.grid)->size))
		{
			vvec_free(parsed_line.vecs);
			break ;
		}
		grid_push_back(ctx.grid, parsed_line.vecs);
		vvu_push_back(ctx.colors, parsed_line.colors);
		line = get_next_line(fd);
	}
	return (ctx);
}
