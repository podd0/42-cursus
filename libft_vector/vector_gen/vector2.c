#include "libft.h"
#include "vector.h"
#include <unistd.h>
#include <stdlib.h>

t_NAME	*NAME_init(int n, TYPE value)
{
	t_NAME	*res;

	res = malloc(sizeof(t_NAME));
	*res = (t_NAME){0, 0, 0};
	NAME_assign(res, n, value);
	return (res);
}

t_NAME	*NAME_uninit(int n)
{
	t_NAME	*res;

	res = malloc(sizeof(t_NAME));
	*res = (t_NAME){0, 0, 0};
	NAME_resize(res, n);
	return (res);
}

void	NAME_free(t_NAME *vec)
{
	free(vec->arr);
	free(vec);
}