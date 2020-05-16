/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_end_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/06 18:45:36 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_atox.h>

size_t		get_word_end_position(const char *string, const char *alphabet)
{
	const size_t	start = get_word_start_position(string, alphabet);
	size_t			position;

	position = start;
	if (!string || !alphabet || !*string)
		return (position);
	while (string[position] && ft_strchr(alphabet, string[position]))
		position++;
	return (position);
}
