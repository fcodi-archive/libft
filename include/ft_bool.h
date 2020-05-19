/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 10:02:08 by bbear             #+#    #+#             */
/*   Updated: 2020/05/19 18:13:32 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOL_H
# define FT_BOOL_H

# define ERROR -1
# define FALSE 0
# define TRUE 1

# include <stdlib.h>
# ifdef __linux
#  include <stdint.h>
# endif

void			set_bit(uint8_t *word, unsigned bit_index);
void			unset_bit(uint8_t *word, unsigned bit_index);
_Bool			validate_mask(const char *mask);
_Bool			set_mask(uint8_t *word, const char *mask);
char			*get_mask(const uint8_t word);
int8_t			byte_shift(void);
uint8_t			byte_start(void);

#endif
