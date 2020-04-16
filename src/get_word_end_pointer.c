#include <ft_atox.h>

char		*get_word_end_pointer(const char *string, const char *alphabet)
{
	const char		*word_start = get_word_start_pointer(string, alphabet);
	size_t 			i;

	if (!word_start)
		return (NULL);
	if (!*string)
		return ((char *)string);
	i = 0;
	while (word_start[i] && ft_strchr(alphabet, word_start[i]))
		i++;
	return ((char *)word_start + i);
}