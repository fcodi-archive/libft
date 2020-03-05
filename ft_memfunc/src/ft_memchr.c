/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 00:43:29 by fcodi             #+#    #+#             */
/*   Updated: 2019/04/28 03:51:33 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memfunc/include/ft_memfunc.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;

	i = -1;
	while (++i < (int)n)
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((void *)s + i);
	return (NULL);
}
