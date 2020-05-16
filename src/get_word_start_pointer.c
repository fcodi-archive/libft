/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_start_pointer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/06 18:45:36 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_atox.h>

char		*get_word_start_pointer(const char *string, const char *alphabet)
{
	size_t		i;

	if (!string || !alphabet)
		return (NULL);
	if (!*string)
		return ((char *)string);
	i = 0;
	while (string[i] && !ft_strchr(alphabet, string[i]))
		i++;
	return ((char *)string + i);
}
