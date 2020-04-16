#include <ft_memfunc.h>

void	*memalloc(const size_t size)
{
	static t_garbage_collector		*collector = NULL;
	void							*ptr;

	if (!size || (!collector && !(collector = get_garbage_collector()))
		|| !(ptr = malloc(size))
		|| !(collector->add(collector, ptr)))
		return (NULL);
	return (ptr);
}