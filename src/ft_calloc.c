#include <ft_memfunc.h>

void	*ft_calloc(const size_t nmemb, const size_t size)
{
	const size_t	full_size = size && nmemb ? size * (nmemb + 1) : 0;
	void			*ptr;

	if (!full_size || !(ptr = ft_malloc(full_size)))
		return (NULL);
	ft_bzero(ptr, full_size);
	return (ptr);
}