/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 10:01:03 by bbear             #+#    #+#             */
/*   Updated: 2020/05/16 10:01:06 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ATOX_H
# define FT_ATOX_H
# include <libft.h>
# include <ft_bool.h>
# include <math.h>
# include <ft_string_array.h>

unsigned long long	ft_atollu_base(const char *string,
		const unsigned short base);
long long			ft_atoll_base(const char *string,
		const unsigned short base);
unsigned long		ft_atolu_base(const char *string,
		const unsigned short base);
long				ft_atol_base(const char *string,
		const unsigned short base);
unsigned			ft_atou_base(const char *string,
		const unsigned short base);
int					ft_atoi_base(const char *string,
		const unsigned short base);
_Bool				ft_atox_validate_number(const char *number,
		const unsigned short base);
_Bool				ft_is_base_digit(const char n,
		const unsigned short base);
int					ft_get_base_digit(const char n);

char				*combine_strings(const char **astr, _Bool free_astr);
char				**parse_integer_array(const char *string);
size_t				get_word_end_position(const char *string,
					const char *alphabet);
size_t				get_word_start_position(const char *string,
					const char *alphabet);
char				*get_word_start_pointer(const char *string,
					const char *alphabet);
char				*get_word_end_pointer(const char *string,
					const char *alphabet);
char				*float_parser_ex(const char *string);
long double			ft_atold_ex(const char *number);
double				ft_atod_ex(const char *number);
float				ft_atof_ex(const char *number);

char				*cut_parse_integer(const char *string);
char				*parse_integer(const char *string);
char				**parse_integers(const char *string);

char				*cut_parse_float_ex(const char *string);
char				*parse_float_ex(const char *string);
char				**parse_floats_ex(const char *string);

#endif
