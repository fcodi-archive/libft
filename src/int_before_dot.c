#include <ft_atox.h>

int128_t	int_before_dot(const char *number)
{
	const size_t	before = digits_before_dot(number);
	int128_t		integer;
	char			*string;

	if ((string = ft_strndup(number, before)) || before)
		integer = ft_atoll_base(string, 10);
	ft_strdel(&string);
	return (integer);
}