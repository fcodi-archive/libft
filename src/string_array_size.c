/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/06 18:45:36 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string_array.h>

size_t	get_string_array_size(char **string_array)
{
	size_t	size;

	size = 0;
	if (string_array && *string_array)
		while (string_array[size])
			size++;
	return (size);
}

size_t	get_string_array_element_size(char **string_array)
{
	size_t	size;
	size_t	i;
	size_t	j;

	size = 0;
	i = 0;
	if (string_array && *string_array)
		while (string_array[i])
		{
			j = 0;
			while (string_array[i][j])
				j++;
			size += j;
			i++;
		}
	return (size);
}
