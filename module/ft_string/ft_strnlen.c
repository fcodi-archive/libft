/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:57:02 by fcodi             #+#    #+#             */
/*   Updated: 2019/04/27 21:54:43 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

unsigned int		ft_strnlen(unsigned int n)
{
	unsigned int	size;

	size = 0;
	while (n >= 10 ? n /= 10 : FALSE)
		++size;
	return (++size);
}
