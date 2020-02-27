/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:07:58 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/04 18:16:31 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNICODE_H
# define FT_UNICODE_H
# define UTF8_MASK_NEXT "10xxxxxx"
# define UTF8_MASK_HEAD_TWO "110xxxxx"
# define UTF8_MASK_HEAD_THREE "1110xxxx"
# define UTF8_MASK_HEAD_FOUR "11110xxx"
# define UTF8_LIMIT_ONE_OCTET_MAX_VALUE 0x0000007Fu
# define UTF8_LIMIT_TWO_OCTET_MIN_VALUE 0x00000080u
# define UTF8_LIMIT_TWO_OCTET_MAX_VALUE 0x000007FFu
# define UTF8_LIMIT_THREE_OCTET_MIN_VALUE 0x00000800u
# define UTF8_LIMIT_THREE_OCTET_MAX_VALUE 0x0000FFFFu
# define UTF8_LIMIT_FOUR_OCTET_MIN_VALUE 0x00010000u
# define UTF8_LIMIT_FOUR_OCTET_MAX_VALUE 0x0010FFFFu
# include <libft.h>

typedef struct		s_utf8
{
	union
	{
		wchar_t		wchar;
		uint8_t		word[sizeof(wchar_t) / sizeof(uint8_t)];
	};
	uint8_t			octet_count;
	char 			*head_mask;
	uint8_t			current_word;
	uint8_t			current_char;
}					t_utf8;

char 				*wchar_to_string(wchar_t wchar);
char 				*get_head_mask(const unsigned octet_count);
unsigned			get_octet_count(const uint32_t word32);

#endif
