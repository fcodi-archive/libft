/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_array.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 10:04:24 by bbear             #+#    #+#             */
/*   Updated: 2020/05/16 10:04:25 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_ARRAY_H
# define FT_STRING_ARRAY_H

# include <ft_string.h>

size_t	get_string_array_size(char **string_array);
size_t	get_string_array_element_size(char **string_array);
void	destroy_string_array(char **string_array);
char	*convert_string_array_to_string(char **string_array);

#endif
