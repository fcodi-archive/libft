/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_mask.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:00:08 by fcodi             #+#    #+#             */
/*   Updated: 2020/03/12 12:59:29 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
**
** @param word
** @param mask
** @return
**/

_Bool 		validate_mask(const char *mask)
{
	uint8_t		i;

	if (!mask)
		return (FALSE);
	i = 0;
	while (mask[i] == '0' || mask[i] == '1' || mask[i] == 'X' || mask[i] == 'x')
		i++;
	if (i < 7)
		return (FALSE);
	return (TRUE);
}

/**
**
** @param word is machine word that transform by mask
** @param mask to transform machine word
** @return
**
**/

_Bool 		set_mask(uint8_t *word, const char *mask)
{
	const int8_t	n_shift = byte_shift();
	uint8_t			n;
	uint8_t			i;

	if (!mask || !validate_mask(mask)
		|| (BYTE_ORDER != LITTLE_ENDIAN && BYTE_ORDER != BIG_ENDIAN))
		return (FALSE);
	n = byte_start();
	i = 0;
	while (mask[i] && i < 8)
	{
		if (mask[i] == '1')
			set_bit(word, n);
		else if (mask[i] == '0')
			unset_bit(word, n);
		i++;
		n += n_shift;
	}
	return (TRUE);
}

/**
**
** @param word
** @return
**
**/

char		*get_mask(const uint8_t word)
{
	const int8_t		n_shift = byte_shift();
	char 				*mask;
	uint8_t				i;
	uint8_t 			n;

	if ((BYTE_ORDER != LITTLE_ENDIAN && BYTE_ORDER != BIG_ENDIAN)
		|| !(mask = ft_strnew(8)))
		return (NULL);
	i = 0;
	n = byte_start();
	while (i < 8 && word > 0)
	{
		if (word & (1u << n))
			mask[i] = '1';
		else
			mask[i] = '0';
		i++;
		n += n_shift;
	}
	return (mask);
}