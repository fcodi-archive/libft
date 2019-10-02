/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:51:03 by fcodi             #+#    #+#             */
/*   Updated: 2019/10/02 21:38:07 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_garbage_collector.h"

t_parray	*gc_new_parray(void)
{
	t_parray	*parray;

	if (!(parray = (t_parray *)malloc(sizeof(t_parray))))
		return (NULL);
	parray->ptr = NULL;
	parray->next = NULL;
	parray->prev = NULL;
	parray->parent = NULL;
	parray->have_childs = FALSE;
	return (parray);
}

void		del_parray(t_parray *current)
{
	if (current)
	{
		current->prev ? (current->prev->next =
				current->next) : FALSE;
		current->next ? (current->next->prev =
				current->prev) : FALSE;
		current->next = NULL;
		current->prev = NULL;
		current->have_childs ? gc_destroy_childhood(current) : FALSE;
		current->parent ?
		(current->parent = NULL) : FALSE;
		current->ptr ? free(current->ptr) : FALSE;
		free(current);
		current = NULL;
	}
}

void		gc_del_parray_all(void)
{
	if (g_collector)
	{
		if (g_collector->tail->prev)
		{
			g_collector->tail = g_collector->tail->prev;
			while ((g_collector->current = g_collector->tail->next))
			{
				gc_del_parray(g_collector->current);
				if (g_collector->tail->prev)
					g_collector->tail = g_collector->tail->prev;
				else
					break ;
			}
		}
		else
		{
			g_collector->current = g_collector->tail;
			gc_del_parray(g_collector->current);
		}
	}
}
