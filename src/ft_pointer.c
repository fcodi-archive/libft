/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/06/14 17:48:28 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pointer_keeper.h"

t_pointer			*new_pointer(void)
{
	t_pointer	*pointer;

	if (!(pointer = (t_pointer *)malloc(sizeof(t_pointer))))
		return (NULL);
	pointer->ptr = NULL;
	pointer->next = NULL;
	pointer->prev = NULL;
	return (pointer);
}

_Bool				add_pointer(t_pointer_keeper *keeper, void *ptr)
{
	if (!keeper || (!keeper->attr.add_null_ptr && !ptr))
		return (FALSE);
	if (keeper->tail)
		keeper->current = keeper->tail;
	if (!(keeper->tail = new_pointer()))
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
