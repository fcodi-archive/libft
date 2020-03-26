#include <ft_atox.h>

int128_t	int_after_dot(const char *number)
{
	const size_t	after = digits_after_dot(number);
	int128_t		integer;

	integer = 0;
	if (after)
		integer = ft_atoll_base(number + after, 10);
	return (integer);
}