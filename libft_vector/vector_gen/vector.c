#include <unistd.h>
#include <stdlib.h>
#include "vector.h"
#include "libft.h"
void	NAME_push_back(t_NAME *vec, TYPE elem)
{
	int	new_buf_size;
	int	c_size;

	if (vec->size >= vec->buf_size)
	{
		c_size = vec->size;
		new_buf_size = vec->buf_size;
		if (new_buf_size < 16)
			new_buf_size = 16;
		NAME_resize(vec, new_buf_size*2);
		vec->size = c_size;
	}
	vec->arr[vec->size] = elem;
	vec->size++;
}

TYPE	NAME_pop_back(t_NAME *vec)
{
	if (vec->size == 0)
	{
		write(2, "Error: pop empty vector\n", 24);
		exit(1);
	}
	vec->size--;
	return (vec->arr[vec->size]);
}

void	NAME_assign(t_NAME *vec, int n, TYPE value)
{
	int	i;

	i = 0;
	vec->size = n;
	vec->buf_size = n;
	free(vec->arr);
	vec->arr = safe_alloc(n * sizeof(TYPE));
	while (i < n)
	{
		vec->arr[i] = value;
		i++;
	}
}

void	NAME_resize(t_NAME *vec, int n)
{
	t_NAME	old;

	old = *vec;
	vec->size = n;
	vec->buf_size = n;
	vec->arr = safe_alloc(n * sizeof(TYPE));
	ft_memcpy(vec->arr, old.arr, old.size * sizeof(TYPE));
	free(old.arr);
}
