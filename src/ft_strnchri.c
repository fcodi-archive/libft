/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnchri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 22:26:47 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strnchri(const char *string, const char c, const size_t i)
{
	size_t	n;

	if (!string)
		return (0);
	n = i;
	while (string[n] && string[n] != c)
		++n;
	return (string[n] != c ? 0 : n);
}
