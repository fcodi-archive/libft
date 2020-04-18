#include <ft_atox.h>

long double		ft_atold_ex(const char *string)
{
	const char 		*dot = ft_strchr(string, '.');
	char 			**parts;
	char 			*raw;
	size_t			size;
	long double		result;

	parts = NULL;
	if (!string || !*string || (dot && (!(parts = ft_strsplit(string, '.')))
	|| (dot && !(raw = join_strings_free(parts[0], parts[1])))))
	{
		parts ? ft_astr_del(parts) : FALSE;
		return (NAN);
	}
	size = dot ? ft_strlen(parts[1]) : 0;
	result = (long double)ft_atoll_base(dot ? raw : string, 10);
	if (size)
		result /= powl(10.0L, size);
	if (result > 0 && *string == '-')
		result *= -1;
	return (result);
}