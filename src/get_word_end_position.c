#include <ft_atox.h>

size_t		get_word_end_position(const char *string, const char *alphabet)
{
	const size_t 	start = get_word_start_position(string, alphabet);
	size_t			position;

	position = start;
	if (!string || !alphabet || !*string)
		return (position);
	while (string[position] && ft_strchr(alphabet, string[position]))
		position++;
	return (position);
}