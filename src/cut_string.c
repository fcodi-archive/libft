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