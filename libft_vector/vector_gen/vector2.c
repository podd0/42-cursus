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

t_NAME	*NAME_copy(t_NAME *vec)
{
	t_NAME	*res;

	res = safe_alloc(sizeof(t_NAME));
	res->size = vec->size;
	res->buf_size = vec->buf_size;
	res->arr = safe_alloc(sizeof(TYPE) * vec->buf_size);
	ft_memmove(res->arr, vec->arr, sizeof(TYPE) * vec->size);
	return (res);
}

void	NAME_map(t_NAME *vec, void (*f)(TYPE))
{
	int	i;

	i = 0;
	while (i < vec->size)
	{
		f(vec->arr[i]);
		i++;
	}
}
