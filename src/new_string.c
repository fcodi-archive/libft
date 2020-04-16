#include <ft_string.h>

char	*new_string(size_t size)
{
	char	*string;

	if (!size)
		return (NULL);
	if ((string = (char *)memalloc(++size)))
		ft_bzero(string, size);
	return (string);
}