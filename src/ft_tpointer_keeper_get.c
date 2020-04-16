#include <ft_tpointer_keeper.h>

t_pointer	*get_tpointer_by_ptr(t_pointer_keeper *keeper, void *ptr)
{
	if (!keeper || !keeper->current)
		return (NULL);
	keeper->current = keeper->head;
	while (keeper->current && keeper->current->ptr != ptr)
		keeper->current = keeper->current->next;
	if (keeper->current && keeper->current->ptr == ptr)
		return (keeper->current);
	else
		keeper->current = keeper->tail;
	return (NULL);
}