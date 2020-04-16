#include <ft_atox.h>

char		*get_word_start_pointer(const char *string, const char *alphabet)
{
	size_t		i;

	if (!string || !alphabet)
		return (NULL);
	if (!*string)
		return ((char *)string);
	i = 0;
	while (string[i] && !ft_strchr(alphabet, string[i]))
		i++;
	return ((char *)string + i);
}