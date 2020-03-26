#include <ft_atox.h>

_Bool	is_valid_float_string_ex(const char *number)
{
	size_t	i;

	i = 0;
	if (number)
		while (number[i])
			if (ft_strchr(VALID_FLOAT_CHARS_EX, number[i]))
				i++;
			else
				return (FALSE);
	else
		return (FALSE);		
	return (TRUE);
}