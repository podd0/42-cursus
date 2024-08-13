/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 00:58:26 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/13 22:50:01 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <stddef.h>
# include "libft.h"

char	*get_next_line(int fd);
char	*double_cum(char *cum, size_t *csize);
size_t	ft_strcpy(char *dst, char *src, size_t i);
int		has_end(char *buf);

#endif