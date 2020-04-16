#include <ft_tpointer_keeper.h>

void	destroy_tpointer_by_ptr(t_pointer_keeper *keeper, void *ptr)
{
	t_pointer	*pointer;

	if (!keeper || !ptr)
		return ;
	if ((pointer = keeper->find_by_ptr(keeper, ptr))
	&& pointer->ptr == ptr)
		keeper->destroy_current(keeper);
}

void 				destroy_tpointer(t_pointer *pointer)
{
	if (!pointer)
		return ;
	if (pointer->next)
		pointer->next->prev = pointer->prev;
	if (pointer->prev)
		pointer->prev->next = pointer->next;
	pointer->ptr = NULL;
	free(pointer);
	pointer = NULL;
}

void 				destroy_tpointer_current(t_pointer_keeper *keeper)
{
	if (!keeper || !keeper->current)
		return ;
	if (keeper->attr.destroy_ptr && keeper->current->ptr)
		free(keeper->current->ptr);
	keeper->destroy(keeper->current);
	keeper->current = NULL;
	keeper->attr.pointer_count--;
}

void				destroy_tpointer_with_attr(t_pointer *pointer,
		t_pointer_keeper_attr *attr)
{
	const _Bool		attr_default = attr ? FALSE : TRUE;

	if (!pointer)
		return ;
	if (!attr && !(attr = get_default_tpointer_keeper_attr()))
		return ;
	if (attr->destroy_ptr && pointer->ptr)
		free(pointer->ptr);
	destroy_tpointer(pointer);
	attr_default ? free(attr) : attr->pointer_count--;
}