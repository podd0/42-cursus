/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:33:37 by apuddu            #+#    #+#             */
/*   Updated: 2025/02/11 20:23:51 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage : %s SCENE\n", argv[0]);
		return (0);
	}
	t_ctx ctx = init(argv[1]);
	trace(&ctx);
	// while(ctx.scene->fov < 180)
	while(1)
	{
		scanf("%f", &ctx.scene->fov);
		// ctx.scene->fov += 1;
		trace(&ctx);
	}
	printf("Finished\n");
	while(1) ;
}

void	pvec(t_vec3 v)
{
	printf("(%f, %f, %f)", v.x, v.y, v.z);
}

void	pframe(t_frame f)
{
	printf("{");
	pvec(f.x);
	printf(",\n");
	pvec(f.y);
	printf(",\n");
	pvec(f.z);
	printf(",\n");
	pvec(f.o);
	printf("}\n");
}

// int _main()
// {
// 	t_frame fr;
// 	fr = rotx(10);
// 	pframe(fr);
// 	printf("\n");
// 	while(1)
// 	{
// 		int x, y;
// 		scanf("%d %d", &x, &y);
// 		float fov = 1.0;
// 		t_vec3 rotated = rotx(y*fov).z;
// 		pvec(rotated);
// 		rotated = to_world(rotated, roty(x*fov));
// 		pvec(rotated);
// 		pvec(to_world(rotated, fr));
// 	}
// }