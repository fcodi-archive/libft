/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:14:26 by fcodi             #+#    #+#             */
/*   Updated: 2019/04/28 03:43:07 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*ft_strnew(size_t size)
{
	char	*string;

	if (size == (size_t)-1)
		return (NULL);
	if ((string = (char *)ft_memalloc(++size)))
		ft_bzero(string, size);
	return (string);
}
