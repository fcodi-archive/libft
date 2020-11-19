/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pointer_keeper.h>

void	destroy_pointer_by_ptr(t_pointer_keeper *keeper, void *ptr)
{
	t_pointer	*pointer;

	if (!keeper || !ptr)
		return ;
	if ((pointer = keeper->find_by_ptr(keeper, ptr))
	&& pointer->ptr == ptr)
		keeper->destroy_current(keeper);
}

void	destroy_pointer(t_pointer *pointer)
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

void	destroy_pointer_current(t_pointer_keeper *keeper)
{
	if (!keeper || !keeper->current)
		return ;
	if (keeper->attr.destroy_ptr && keeper->current->ptr)
		free(keeper->current->ptr);
	keeper->destroy(keeper->current);
	keeper->current = NULL;
	keeper->attr.pointer_count--;
}

void	destroy_pointer_with_attr(t_pointer *pointer,
		t_pointer_keeper_attr *attr)
{
	const _Bool		attr_default = attr ? FALSE : TRUE;

	if (!pointer)
		return ;
	if (!attr && !(attr = get_default_pointer_keeper_attr()))
		return ;
	if (attr->destroy_ptr && pointer->ptr)
		free(pointer->ptr);
	destroy_pointer(pointer);
	attr_default ? free(attr) : attr->pointer_count--;
}
