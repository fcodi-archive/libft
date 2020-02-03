/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:41:53 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/03 08:49:14 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

_Bool			ft_ishex(const char c)
{
	const char	symbol = (char)ft_tolower(c);

	if (ft_isdigit(symbol) || (symbol >= 'a' && symbol <= 'f'))
		return (TRUE);
	return (FALSE);
}
