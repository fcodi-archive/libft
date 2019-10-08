/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atollu_base.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:38:49 by fcodi             #+#    #+#             */
/*   Updated: 2019/10/08 20:41:10 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NO_MATH_H
# ifndef FT_ATOX_BASE_H
#  include "libft.h"
#  include <math.h>
#  define FT_ATOX_BASE_H

unsigned long long	ft_atollu_base
(const char *string, const unsigned short base);
long long			ft_atoll_base
(const char *string, const unsigned short base);
unsigned long		ft_atolu_base
(const char *string, const unsigned short base);
long				ft_atol_base
(const char *string, const unsigned short base);
unsigned			ft_atou_base
(const char *string, const unsigned short base);
int					ft_atoi_base
(const char *string, const unsigned short base);
_Bool				ft_atox_validate_number
(const char *number, const unsigned short base);
_Bool				ft_is_base_digit(const char n, const unsigned short base);
int 				ft_get_base_digit(const char n);

# endif
#endif
