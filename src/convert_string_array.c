/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owl <owl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 06:42:13 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string_array.h>

char	*convert_string_array_to_string(char **string_array)
{
	char	*result;
	size_t	i;

	if (!string_array || !*string_array || !(result = new_string(
			get_string_array_element_size(string_array))))
		return (NULL);
	result = ft_strcpy(result, *string_array);
	i = 1;
	while (string_array[i])
		result = ft_strcat(result, string_array[i++]);
	return (result);
}
