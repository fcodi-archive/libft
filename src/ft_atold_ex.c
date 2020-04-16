#include <ft_atox.h>

long double		ft_atold_ex(const char *string)
{
	char 			**parts;
	char 			*raw;
	size_t			size;
	long double		result;

	if (!string || !(parts = ft_strsplit(string, '.'))
	|| !(raw = join_strings_free(parts[0], parts[1])))
		return (NAN);
	size = ft_strlen(parts[1]);
	result = (long double)ft_atoll_base(raw, 10);
	if (size)
		result /= powl(10.0L, size);
	if (result > 0 && **parts == '-')
		result += -1;
	return (result);
}