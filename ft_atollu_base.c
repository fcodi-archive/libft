/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atollu_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:32:58 by fcodi             #+#    #+#             */
/*   Updated: 2019/10/08 20:31:09 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atox_base.h"

unsigned long long	ft_atollu_base
(const char *string, const unsigned short base)
{
	unsigned long long		number;
	unsigned short			power;
	size_t					index;
	_Bool					result;

	if (!string)
		return (0);
	*string == '+' || *string == '-' ?
	(result = ft_atox_validate_number(++string, base))
	: (result = ft_atox_validate_number(string, base));
	if (!result)
		return (0);
	power = ft_strlen(string);
	number = 0;
	index = *string == '-' || *string == '+' ? 1 : 0;
	while (string[index])
		number += ft_get_base_digit(string[index++]) * pow(base, --power);
	return (number);
}
