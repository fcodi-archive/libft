/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:34:03 by fcodi             #+#    #+#             */
/*   Updated: 2020/01/06 14:34:08 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *string, size_t n)
{
	char	*new_string;

	if (!(new_string = ft_strnew(n)))
		return (NULL);
	new_string = ft_strncpy(new_string, string, n);
	return (new_string);
}
