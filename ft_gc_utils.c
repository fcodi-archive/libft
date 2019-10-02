/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:51:11 by fcodi             #+#    #+#             */
/*   Updated: 2019/10/02 21:38:07 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_garbage_collector.h"

t_parray				*gc_get_parray_by_ptr(void *ptr)
{
	g_collector->current = g_collector->head;
	while (g_collector->current && g_collector->current->ptr != ptr)
		g_collector->current = g_collector->current->next;
	return (g_collector->current->ptr == ptr ? g_collector->current : NULL);
}

t_parray				*gc_get_parray_by_parent(t_parray *parent, _Bool first)
{
	g_collector->current = first ? g_collector->head : g_collector->tail;
	while (g_collector->current && g_collector->current->parent != parent)
		g_collector->current = first ?
				g_collector->current->next : g_collector->current->prev;
	return (g_collector->current && g_collector->current->parent == parent ?
			g_collector->current : NULL);
}

void					gc_destroy_childhood(t_parray *parent)
{
	t_parray	*child;

	parent->have_childs ? (parent->have_childs = FALSE) : FALSE;
	while ((child = gc_get_parray_by_parent(parent, TRUE)))
		gc_del_parray(child);
}
