/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/06 18:45:36 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tpointer_keeper.h"

t_pointer			*new_tpointer(void)
{
	t_pointer	*pointer;

	if (!(pointer = (t_pointer *)malloc(sizeof(t_pointer))))
		return (NULL);
	pointer->ptr = NULL;
	pointer->next = NULL;
	pointer->prev = NULL;
	return (pointer);
}

_Bool				add_tpointer(t_pointer_keeper *keeper, void *ptr)
{
	if (!keeper || (!keeper->attr.add_null_ptr && !ptr))
		return (FALSE);
	if (keeper->tail)
		keeper->current = keeper->tail;
	if (!(keeper->tail = new_tpointer()))
		return (FALSE);
	keeper->tail->ptr = ptr;
	if (keeper->current)
	{
		keeper->current->next = keeper->tail;
		keeper->tail->prev = keeper->current;
	}
	else
	{
		keeper->head = keeper->tail;
		keeper->current = keeper->tail;
	}
	keeper->attr.pointer_count++;
	return (TRUE);
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
	destroy_tpointer(keeper->current);
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