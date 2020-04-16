#include <ft_memfunc.h>

void	*memadd(void *ptr)
{
	static t_garbage_collector	*collector = NULL;

	if (!collector)
		collector = get_garbage_collector();
	if (!get_tpointer_by_ptr(collector, ptr))
		collector->add(collector, ptr);
	return (ptr);
}