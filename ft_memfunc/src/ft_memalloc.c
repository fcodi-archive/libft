/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:26:50 by fcodi             #+#    #+#             */
/*   Updated: 2019/04/27 21:08:02 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memfunc/include/ft_memfunc.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*result;

	if ((result = malloc(sizeof(unsigned char) * size)))
	{
		i = 0;
		while (i < size)
			*((unsigned char *)result + i++) = 0;
	}
	return (result);
}
