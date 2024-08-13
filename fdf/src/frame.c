#include "fdf.h"

t_vec3	to_frame(t_vec3 p, t_frame fr)
{
	t_vec3 res = sub(p, fr.o);
	res = (t_vec3){dot(res, fr.x), dot(res, fr.y), dot(res, fr.z)};
	return (res);
}

t_vec3	to_world(t_vec3 p, t_frame fr)
{
	t_vec3 res = add(p, fr.o); 
	res = add(scale(p.x, fr.x), scale(p.y, fr.y));
	return (add(res, scale(p.z, fr.z)));
}
