/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:34:30 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/03 08:49:14 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atox_base.h"

long long	ft_atoll_base(const char *string, const unsigned short base)
{
	_Bool				is_minus;
	unsigned long long	result;

	if (!string || base == 0)
		return (0);
	*string == '-' ? (is_minus = TRUE)
	: (is_minus = FALSE);
	result = ft_atollu_base(string, base);
	return (is_minus ? ((long long)result) * (-1) : ((long long)result));
}
