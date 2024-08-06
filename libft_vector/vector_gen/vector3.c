#include "libft.h"
#include "vector.h"
#include <unistd.h>
#include <stdlib.h>

TYPE	NAME_back(t_NAME *vec)
{
	return (vec->arr[vec->size - 1]);
}
