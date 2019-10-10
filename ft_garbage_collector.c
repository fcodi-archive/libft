/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:50:55 by fcodi             #+#    #+#             */
/*   Updated: 2019/10/10 15:14:28 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_garbage_collector.h"

__attribute__ ((destructor)) void		destroy_collector(void)
{
	if (g_collector)
	{
		if (g_collector->head)
			gc_del_parray_all();
		g_collector->head = NULL;
		g_collector->current = NULL;
		g_collector->tail = NULL;
		free(g_collector);
		g_collector = NULL;
	}
}

void									*new(void *ptr)
{
	g_collector->current = g_collector->tail;
	if (!ptr || !(g_collector->tail = gc_new_parray()))
	{
		if (GC_FAIL_ACTION == GC_ALL)
			exit(GC_ERROR_MALLOC);
		else
			return (ptr);
	}
	if (g_collector->current)
	{
		g_collector->tail->prev = g_collector->current;
		g_collector->current->next = g_collector->tail;
	}
	else
	{
		g_collector->current = g_collector->tail;
		g_collector->head = g_collector->tail;
	}
	g_collector->tail->ptr = ptr;
	return (ptr);
}

void									*fnew(void *ptr, void *parent_ptr)
{
	if (new(ptr))
	{
		if (parent_ptr)
			g_collector->tail->parent = gc_get_parray_by_ptr(parent_ptr);
		else
			g_collector->current->have_childs = TRUE;
	}
	return (ptr);
}

__attribute__ ((constructor)) _Bool		init_collector(void)
{
	if (!(g_collector = (t_collector *)malloc(sizeof(t_collector))))
		return (FALSE);
	g_collector->current = NULL;
	g_collector->head = NULL;
	g_collector->tail = NULL;
	return (TRUE);
}
