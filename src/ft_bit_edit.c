/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:59:23 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bool.h"

void		set_bit(uint8_t *word, unsigned bit_index)
{
	if (bit_index >= 8u)
		return ;
	*word |= (1u << bit_index);
}

void		unset_bit(uint8_t *word, unsigned bit_index)
{
	if (bit_index >= 8u)
		return ;
	*word &= ~(1u << bit_index);
}
