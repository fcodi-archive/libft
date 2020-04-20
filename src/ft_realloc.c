#include <ft_memfunc.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr)
		return (NULL);
	if (!(new = ft_malloc(size)))
		new = NULL;
	new ? new = ft_strcpy(new, ptr) : FALSE;
	ft_free(ptr);
	return (new);
}