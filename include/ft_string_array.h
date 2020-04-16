#ifndef FT_STRING_ARRAY_H
# define FT_STRING_ARRAY_H

# include <ft_string.h>

size_t 	get_string_array_size(const char **string_array);
size_t	get_string_array_element_size(const char **string_array);
void 	destroy_string_array(char **string_array);
char	*convert_string_array_to_string(char **string_array);

#endif
