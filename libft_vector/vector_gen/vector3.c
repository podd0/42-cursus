#include "libft.h"
#include "vector.h"
#include <unistd.h>
#include <stdlib.h>

TYPE	NAME_back(t_NAME *vec)
{
	return (vec->arr[vec->size - 1]);
}

void	NAME_map_sub(t_NAME *vec, TYPE (*f)(TYPE))
{
	int	i;

	i = 0;
	while (i < vec->size)
	{
		vec->arr[i] = f(vec->arr[i]);
		i++;
	}
}
