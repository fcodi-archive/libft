#include <ft_string_array.h>

void 	destroy_string_array(char **string_array)
{
	size_t		i;

	if (!string_array)
		return ;
	i = 0;
	while (string_array[i])
		free(string_array[i++]);
	free(string_array);
}