/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:48:13 by fcodi             #+#    #+#             */
/*   Updated: 2020/03/05 19:50:47 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

size_t	ft_strlenc(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] && s[size] != c)
		++size;
	return (size);
}
