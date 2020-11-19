/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_float_ex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_atox.h>

char	*cut_parse_float_ex(const char *string)
{
	char	*integer;
	size_t	i;
	_Bool	dot;

	if (!string)
		return (NULL);
	dot = FALSE;
	i = ft_strchr("+-", *string) ? 1 : 0;
	string[i] == '0' ? i++ : FALSE;
	if (string[i] != '0')
		while (string[i])
		{
			while (string[i] && ft_strchr("1234567890", string[i]))
				i++;
			if (string[i] && string[i] == '.' ? (dot = !dot) : FALSE)
				i++;
			else
				break ;
		}
	if (!(integer = cut_string_part(string, i)))
		return (NULL);
	return (integer);
}

char	*parse_float_ex(const char *string)
{
	char	*string_pointer;
	char	*result;

	if (!string || !(string_pointer = get_word_start_pointer(
			string, "-+1234567890"))
		|| !(result = cut_parse_float_ex(string_pointer)))
		return (NULL);
	return (result);
}

char	**parse_floats_ex(const char *string)
{
	t_pointer_keeper	*keeper;
	char				*string_pointer;
	char				*result;

	if (!string || !(keeper = new_pointer_keeper()))
		return (NULL);
	string_pointer = (char *)string;
	while (string_pointer && *string_pointer)
		if ((result = parse_float_ex(string_pointer))
			&& (keeper->add(keeper, result)))
			string_pointer += get_word_start_position(string_pointer,
					"+-1234567890") + ft_strlen(result);
		else
		{
			free(result);
			destroy_pointer_keeper(&keeper);
			return (NULL);
		}
	return ((char **)keeper->convert(keeper));
}
