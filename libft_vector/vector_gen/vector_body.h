
struct	s_NAME
{
	TYPE	*arr;
	int		size;
	int		buf_size;
};

typedef struct s_NAME	t_NAME;

void	NAME_push_back(t_NAME *vec, TYPE elem);
TYPE	NAME_pop_back(t_NAME *vec);
void	NAME_assign(t_NAME *vec, int n, TYPE value);
void	NAME_resize(t_NAME *vec, int n);
t_NAME	*NAME_init(int n, TYPE value);
t_NAME	*NAME_uninit(int n);
void	NAME_free(t_NAME *vec);
t_NAME	*NAME_copy(t_NAME *vec);
void	NAME_map(t_NAME *vec, void (*f)(TYPE));
void	NAME_map_sub(t_NAME *vec, TYPE (*f)(TYPE));
TYPE	NAME_back(t_NAME *vec);