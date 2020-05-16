/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold_ex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:59:23 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/04 18:16:31 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_atox.h>

long double		ft_atold_ex(const char *string)
{
	const char		*dot = ft_strchr(string, '.');
	char			**parts;
	char			*raw;
	size_t			size;
	long double		result;

	result = 0.0L;
	parts = NULL;
	raw = NULL;
	if (!string || !*string || (dot && (!(parts = ft_strsplit(string, '.'))))
	|| (dot && !(raw = ft_strjoin(parts[0], parts[1]))))
		result = NAN;
	size = dot && parts && parts[1] ? ft_strlen(parts[1]) : 0;
	dot && parts ? ft_astr_del(parts) : FALSE;
	if (isnan(result))
		return (result);
	result = (long double)ft_atoll_base(dot ? raw : string, 10);
	if (size)
		result /= powl(10.0L, size);
	if (result > 0 && *string == '-')
		result *= -1;
	raw ? ft_strdel(&raw) : FALSE;
	return (result);
}
