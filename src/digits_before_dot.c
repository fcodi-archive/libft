#include <ft_atox.h>

size_t	digits_before_dot(const char *number)
{
	size_t	i;

	if (!is_valid_float_string_ex(number))
		return (0);
	i = 0;
	while (number[i] && number[i] != '.')
		i++;
	return (i);
}