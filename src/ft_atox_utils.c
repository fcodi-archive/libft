/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:30:45 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_atox.h>

int					ft_get_base_digit(const char n)
{
	if (n >= '0' && n <= '9')
		return (n - '0');
	else
		return (ft_islower(n) ? n - 'a' + 10 : n - 'A' + 10);
}

_Bool				ft_is_base_digit(const char n,
									const unsigned short base)
{
	int				digit;

	digit = n - '0' > 9 ? ft_get_base_digit(n) : n - '0';
	return (digit >= 0 && digit < base ? TRUE : FALSE);
}

_Bool				ft_atox_validate_number(const char *number,
											const unsigned short base)
{
	size_t			i;

	i = 0;
	while (number[i] && ft_is_base_digit(number[i], base))
		++i;
	return (ft_strlen(number) == i ? TRUE : FALSE);
}
