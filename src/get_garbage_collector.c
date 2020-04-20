#include <ft_garbage_collector.h>

t_garbage_collector		*get_garbage_collector(void)
{
	static t_garbage_collector		*collector = NULL;

	if (collector)
		return (collector);
	else if (!(collector = (t_garbage_collector *)new_tpointer_keeper()))
		return (NULL);
	collector->attr.destroy_ptr = TRUE;
	return (collector);
}
