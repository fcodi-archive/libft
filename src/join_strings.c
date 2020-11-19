/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

char	*join_strings(const char *string1, const char *string2)
{
	char	*result;

	if (!string1 || !string2
		|| !(result = ft_strnew(ft_strlen(string1) + ft_strlen(string2))))
		return (NULL);
	result = ft_strcpy(result, string1);
	result = ft_strcat(result, string2);
	return (result);
}

char	*join_strings_free(char *string1, char *string2)
{
	char	*result;

	if (!string1 || !string2 || !(result = ft_strjoin(string1, string2)))
		return (NULL);
	free(string1);
	free(string2);
	return (result);
}
