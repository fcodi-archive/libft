/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owl <owl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 07:09:10 by owl               #+#    #+#             */
/*   Updated: 2020/05/15 07:09:13 by owl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*cut_string_part(const char *string, const size_t part_size)
{
	char	*result;

	if (!(result = new_string(part_size)))
		return (NULL);
	result = ft_strncpy(result, string, part_size);
	return (result);
}

char	*cut_string(const char *string)
{
	char	*result;

	if (!(result = new_string(ft_strlen(string) + 1)))
		return (NULL);
	result = ft_strcpy(result, string);
	return (result);
}
