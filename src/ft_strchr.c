/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 03:41:48 by fcodi             #+#    #+#             */
/*   Updated: 2020/06/14 17:07:48 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strchr(const char *string, int c)
{
	int		i;

	if (!string)
		return (NULL);
	i = -1;
	while (string[++i])
		if (string[i] == (char)c)
			return ((char *)string + i);
	if (string[i] == (char)c)
		return ((char *)string + i);
	return (NULL);
}
