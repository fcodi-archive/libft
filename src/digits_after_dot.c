#include <ft_atox.h>

size_t	digits_after_dot(const char *number)
{
	char	*string;
	size_t	i;

	if (!is_valid_float_string_ex(number))
		return (0);
	string = ft_strchr(number, '.');
	i = 0;
	while (string[i])
		i++;
	return (i);
}