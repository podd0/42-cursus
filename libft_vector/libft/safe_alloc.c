#include "libft.h"
#include <stdlib.h>

void	*safe_alloc(int bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
	{
		ft_putendl_fd("Error: malloc fail", 2);
		exit(1);
	}
	return (ptr);
}