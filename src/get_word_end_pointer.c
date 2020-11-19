/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_end_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_atox.h>

char		*get_word_end_pointer(const char *string, const char *alphabet)
{
	const char		*word_start = get_word_start_pointer(string, alphabet);
	size_t			i;

	if (!word_start)
		return (NULL);
	if (!*string)
		return ((char *)string);
	i = 0;
	while (word_start[i] && ft_strchr(alphabet, word_start[i]))
		i++;
	return ((char *)word_start + i);
}
