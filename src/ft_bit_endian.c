/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_endian.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:01:54 by fcodi             #+#    #+#             */
/*   Updated: 2020/05/15 07:13:42 by owl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bool.h"

int8_t		byte_shift(void)
{
	if (BYTE_ORDER == LITTLE_ENDIAN)
		return (-1);
	else if (BYTE_ORDER == BIG_ENDIAN)
		return (1);
	else
		return (0);
}

uint8_t		byte_start(void)
{
	if (BYTE_ORDER == LITTLE_ENDIAN)
		return (7);
	else if (BYTE_ORDER == BIG_ENDIAN)
		return (0);
	else
		return ((uint8_t)-1);
}
