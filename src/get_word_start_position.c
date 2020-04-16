#include <ft_atox.h>

size_t		get_word_start_position(const char *string, const char *alphabet)
{
	size_t	position;

	position = 0;
	if (!string || !alphabet || !*string)
		return (position);
	while (string[position] && !ft_strchr(alphabet, string[position]))
		position++;
	return (position);
}