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

void				destroy_tpointer(t_pointer *tpointer,
		t_pointer_keeper_attr *attr)
{
	if (!tpointer)
		return ;
	if (tpointer->next)
		tpointer->next->prev = tpointer->prev;
	if (tpointer->prev)
		tpointer->prev->next = tpointer->next;
	if (attr->free_ptr && tpointer->ptr)
		free(tpointer->ptr);
	free(tpointer);
	attr->size--;
}

static t_pointer	*new_tpointer(void)
{
	static size_t	number = 0;
	t_pointer		*tpointer;

	if (!(tpointer = (t_pointer *)malloc(sizeof(t_pointer))))
		return (NULL);
	tpointer->id = 0;
	tpointer->tag = NULL;
	tpointer->ptr = NULL;
	tpointer->next = NULL;
	tpointer->prev = NULL;
	tpointer->number = number++;
	return (tpointer);
}

_Bool 				add_tpointer(t_pointer_keeper *keeper, void *ptr)
{
	if (!keeper || (keeper->attr.skip_null_ptr && !ptr))
		return (FALSE);
	if (keeper->tail)
		keeper->current = keeper->tail;
	if (!(keeper->tail = new_tpointer()))
		return (FALSE);
	keeper->tail->ptr = ptr;
	if (keeper->current)
	{
		keeper->tail->prev = keeper->current;
		keeper->current->next = keeper->tail;
	}
	else
	{
		keeper->current = keeper->tail;
		keeper->head = keeper->tail;
	}
	keeper->attr.size++;
	return (TRUE);
}

_Bool 				add_tpointer_with_id(
		t_pointer_keeper *keeper, void *ptr, size_t id)
{
	_Bool 		result;

	if ((result = add_tpointer(keeper, ptr)))
		keeper->tail->id = id;
	return (result);
}

_Bool 				add_tpointer_with_tag(
		t_pointer_keeper *keeper, void *ptr, char *tag)
{
	_Bool 		result;

	if ((result = add_tpointer(keeper, ptr)))
		keeper->tail->tag = tag;
	return (result);
}