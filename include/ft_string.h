#ifndef FT_STRING_H
# define FT_STRING_H

# include <libft.h>

char	*new_string(size_t size);
char	*cut_string(const char *string);
char	*cut_string_part(const char *string, const size_t part_size);
char	*join_strings(const char *string1, const char *string2);
char	*join_strings_free(char *string1, char *string2);

#endif
