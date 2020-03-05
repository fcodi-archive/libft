/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 00:52:54 by fcodi             #+#    #+#             */
/*   Updated: 2019/04/28 03:36:59 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memfunc/include/ft_memfunc.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;

	i = -1;
	while (++i < (int)n)
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return ((int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
	return (0);
}
