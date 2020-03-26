#include <ft_atox.h>

long double	ft_atold_ex(const char *number)
{
	const size_t		after = digits_after_dot(number) - 1;
	const unsigned		power = powl(10 , after);
	const long double	integer = int_before_dot(number);
	long double			fraction;

	fraction = (long double)int_after_dot(number) / power;
	return (integer + fraction);
}