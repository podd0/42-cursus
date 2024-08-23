/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuddu <apuddu@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:17:16 by apuddu            #+#    #+#             */
/*   Updated: 2024/08/19 20:50:33 by apuddu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) < 0)
		exit(1);
}
