/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:58:35 by apuddu            #+#    #+#             */
/*   Updated: 2024/11/02 22:23:41 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <vector.h>
# include <mlx.h>

struct							s_vec3
{
	float						x;
	float						y;
	float						z;
};

typedef struct s_vec3			t_vec3;

struct							s_frame
{
	t_vec3						x;
	t_vec3						y;
	t_vec3						z;
	t_vec3						o;
};

typedef struct s_frame			t_frame;

typedef struct s_img
{
	void						*img;
	char						*addr;
	int							bits_per_pixel;
	int							line_length;
	int							endian;
	float						*z_buf;
}								t_img;


#endif