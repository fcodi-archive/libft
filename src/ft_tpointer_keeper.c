/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpointer_keeper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:53:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/06 19:39:36 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tpointer_keeper.h"

void				destroy_tpointer_all(t_pointer_keeper *keeper)
{
	if (!keeper || !keeper->head)
		return ;
	keeper->current = keeper->head;
	while (keeper->current->next && (keeper->current = keeper->current->next))
		destroy_tpointer_with_attr(keeper->current->prev, &keeper->attr);
	destroy_tpointer_current(keeper);
	keeper->attr.pointer_count = 0;
}

void				destroy_tpointer_last_count(t_pointer_keeper *keeper,
		size_t count)
{
	if (!keeper || !count || !keeper->tail)
		return ;
	calc_tpointer_count(keeper);
	if (!keeper->attr.ignore_pointer_count_when_destroy
		&& keeper->attr.pointer_count < count++)
		return ;
	keeper->current = keeper->tail;
	while (--count && keeper->current->prev
		   && (keeper->current = keeper->current->prev))
		destroy_tpointer_with_attr(keeper->current->next, &keeper->attr);
}

void				destroy_tpointer_keeper(t_pointer_keeper **keeper)
{
	if (!keeper)
		return ;
	destroy_tpointer_all(*keeper);
	free(*keeper);
	*keeper = NULL;
}

t_pointer_keeper	*new_tpointer_keeper(void)
{
	t_pointer_keeper	*keeper;

	if (!(keeper = (t_pointer_keeper *)malloc(sizeof(t_pointer_keeper))))
		return (NULL);
	init_tpointer_keeper_attr(&keeper->attr);
	keeper->current = NULL;
	keeper->head = NULL;
	keeper->tail = NULL;
	keeper->add = add_tpointer;
	keeper->destroy = destroy_tpointer;
	keeper->destroy_current = destroy_tpointer_current;
	keeper->destroy_all = destroy_tpointer_all;
	keeper->destroy_keeper = destroy_tpointer_keeper;
	keeper->convert_to_matrix = convert_tpointer_keeper_to_matrix;
	keeper->destroy_attr = destroy_tpointer_with_attr;
	keeper->destroy_last_count = destroy_tpointer_last_count;
	keeper->matrix_convert = add_matrix_to_tpointer_array;
	return (keeper);
}