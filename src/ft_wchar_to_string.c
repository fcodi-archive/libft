/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:06:29 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/04 18:16:31 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_unicode.h"

unsigned			get_octet_count(const uint32_t word32)
{
	if (word32 <= UTF8_LIMIT_ONE_OCTET_MAX_VALUE)
		return (1);
	if (word32 >= UTF8_LIMIT_TWO_OCTET_MIN_VALUE
	&& word32 <= UTF8_LIMIT_TWO_OCTET_MAX_VALUE)
		return (2);
	if (word32 >= UTF8_LIMIT_THREE_OCTET_MIN_VALUE
	&& word32 <= UTF8_LIMIT_THREE_OCTET_MAX_VALUE)
		return (3);
	if (word32 >= UTF8_LIMIT_FOUR_OCTET_MIN_VALUE
	&& word32 <= UTF8_LIMIT_FOUR_OCTET_MAX_VALUE)
		return (4);
	return (0);
}

char				*get_head_mask(const unsigned octet_count)
{
	if (octet_count == 2)
		return (UTF8_MASK_HEAD_TWO);
	if (octet_count == 3)
		return (UTF8_MASK_HEAD_THREE);
	if (octet_count == 4)
		return (UTF8_MASK_HEAD_FOUR);
	return (0);
}

static _Bool		init_tutf8(t_utf8 *utf, const wchar_t wchar)
{
	if (!utf || (utf->octet_count = get_octet_count(wchar)) == 1)
		return (FALSE);
	utf->head_mask = get_head_mask(utf->octet_count);
	utf->wchar = wchar;
	utf->current_char = utf->octet_count - 1;
	utf->current_word = 0;
	return (TRUE);
}

static char			get_utf8_symbol_next_part(t_utf8 utf)
{
	uint8_t		shift;
	uint8_t		result;

	shift = utf.current_char == utf.octet_count - 1
			? 0 : 8 + (2 * utf.current_word);
	utf.wchar <<= shift;
	result = utf.word[utf.current_word ? utf.current_word + 1 : 0];
	if (!set_mask(&result, utf.current_char ? UTF8_MASK_NEXT : utf.head_mask))
		return ('\0');
	return ((char)result);
}

char				*wchar_to_string(wchar_t wchar)
{
	t_utf8				utf;
	char				*string;

	init_tutf8(&utf, wchar);
	if (!(string = ft_strnew(utf.octet_count)))
		return (NULL);
	if (utf.octet_count == 1)
		*string = (char)wchar;
	else
		while (utf.current_char != (uint8_t)-1)
		{
			if (!(string[utf.current_char] = get_utf8_symbol_next_part(utf)))
				return (NULL);
			utf.current_char--;
			utf.current_word++;
		}
	return (string);
}
