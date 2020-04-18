#include <ft_memfunc.h>

void	memfree(void *ptr)
{
	static t_garbage_collector		*collector = NULL;

	if (!ptr)
		return ;
	if (!collector)
		collector = get_garbage_collector();
	if (ptr == memfree && collector)
	{
		destroy_tpointer_keeper((t_pointer_keeper **)&collector);
		collector = NULL;
	}
	if (collector)
	{
		destroy_tpointer_by_ptr(collector, ptr);
		ptr = NULL;
	}
}