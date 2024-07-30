/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 01:37:53 by apuddu            #+#    #+#             */
/*   Updated: 2024/07/30 01:37:53 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H 1

struct					s_vi
{
	int					*arr;
	int					size;
	int					buf_size;
};

typedef struct s_vi		t_vi;

void					vi_push_back(t_vi *vec, int elem);
int						vi_pop_back(t_vi *vec);
void					vi_assign(t_vi *vec, int n, int value);
void					vi_resize(t_vi *vec, int n);
t_vi					*vi_init(int n, int value);
t_vi					*vi_uninit(int n);
void					vi_free(t_vi *vec);

struct					s_vl
{
	long				*arr;
	int					size;
	int					buf_size;
};

typedef struct s_vl		t_vl;

void					vl_push_back(t_vl *vec, long elem);
long					vl_pop_back(t_vl *vec);
void					vl_assign(t_vl *vec, int n, long value);
void					vl_resize(t_vl *vec, int n);
t_vl					*vl_init(int n, long value);
t_vl					*vl_uninit(int n);
void					vl_free(t_vl *vec);

struct					s_vlu
{
	long unsigned int	*arr;
	int					size;
	int					buf_size;
};

typedef struct s_vlu	t_vlu;

void					vlu_push_back(t_vlu *vec, long unsigned int elem);
long unsigned int		vlu_pop_back(t_vlu *vec);
void					vlu_assign(t_vlu *vec, int n, long unsigned int value);
void					vlu_resize(t_vlu *vec, int n);
t_vlu					*vlu_init(int n, long unsigned int value);
t_vlu					*vlu_uninit(int n);
void					vlu_free(t_vlu *vec);

#endif
