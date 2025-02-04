/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 22:59:28 by apuddu            #+#    #+#             */
/*   Updated: 2024/11/19 15:32:24 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

// initialize scene with the contents of filename and return scene,
// return NULL and free scene on error
t_scene	*parse_init(t_scene *scene, char *filename)
{}

t_scene	*parse(char *filename)
{
	int		fd;
	t_scene	*scene;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (NULL);
	}
	scene = malloc(sizeof(t_scene));
	return (parse_init(scene, filename));
}
