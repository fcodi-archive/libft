/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 23:34:30 by fcodi             #+#    #+#             */
/*   Updated: 2019/10/08 20:27:54 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atox_base.h"

long long	ft_atoll_base(const char *string, const unsigned short base)
{
	_Bool				isMinus;
	unsigned long long	result;

	if (!string || base == 0)
		return (0);
	*string == '-' ? (isMinus = TRUE) : (isMinus = FALSE);
	result = ft_atollu_base(string, base);
	return (isMinus ? ((long long)result) * (-1) : ((long long)result));
}
