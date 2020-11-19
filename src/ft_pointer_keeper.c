/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_keeper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:53:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pointer_keeper.h>

void				destroy_pointer_all(t_pointer_keeper *keeper)
{
	if (!keeper || !keeper->head)
		return ;
	keeper->current = keeper->head;
	while (keeper->current->next && (keeper->current = keeper->current->next))
		destroy_pointer_with_attr(keeper->current->prev, &keeper->attr);
	destroy_pointer_current(keeper);
	keeper->attr.pointer_count = 0;
}

void				destroy_pointer_last_count(t_pointer_keeper *keeper,
											   size_t count)
{
	if (!keeper || !count || !keeper->tail)
		return ;
	calc_pointer_count(keeper);
	if (!keeper->attr.ignore_pointer_count_when_destroy
		&& keeper->attr.pointer_count < count++)
		return ;
	keeper->current = keeper->tail;
	while (--count && keeper->current->prev
			&& (keeper->current = keeper->current->prev))
		destroy_pointer_with_attr(keeper->current->next, &keeper->attr);
}

void				destroy_pointer_keeper(t_pointer_keeper **keeper)
{
	if (!keeper)
		return ;
	destroy_pointer_all(*keeper);
	free(*keeper);
	*keeper = NULL;
}

t_pointer_keeper	*new_pointer_keeper(void)
{
	t_pointer_keeper	*keeper;

	if (!(keeper = (t_pointer_keeper *)malloc(sizeof(t_pointer_keeper))))
		return (NULL);
	init_pointer_keeper_attr(&keeper->attr);
	keeper->current = NULL;
	keeper->head = NULL;
	keeper->tail = NULL;
	keeper->add = add_pointer;
	keeper->destroy = destroy_pointer;
	keeper->destroy_current = destroy_pointer_current;
	keeper->destroy_all = destroy_pointer_all;
	keeper->destroy_keeper = destroy_pointer_keeper;
	keeper->convert = convert_pointer_keeper_to_matrix;
	keeper->destroy_attr = destroy_pointer_with_attr;
	keeper->destroy_last_count = destroy_pointer_last_count;
	keeper->matrix_convert = add_matrix_to_keeper;
	keeper->find_by_ptr = get_pointer_by_ptr;
	keeper->destroy_by_ptr = destroy_pointer_by_ptr;
	return (keeper);
}

t_pointer_keeper	*new_pointer_keeper_with_attr(t_pointer_keeper_attr *attr)
{
	t_pointer_keeper	*keeper;

	if (!(keeper = new_pointer_keeper()))
		return (NULL);
	if (attr)
		copy_pointer_keeper_attr(attr, &keeper->attr);
	return (keeper);
}
