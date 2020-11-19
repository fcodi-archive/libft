/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_keeper_attr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:55:07 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pointer_keeper.h>

void					init_pointer_keeper_attr(t_pointer_keeper_attr *attr)
{
	attr->pointer_count = 0;
	attr->destroy_ptr = FALSE;
	attr->add_null_ptr = FALSE;
	attr->destroy_on_error = TRUE;
	attr->ignore_pointer_count_when_destroy = TRUE;
	attr->destroy_added_matrix = TRUE;
	attr->destroy_keeper_after_converting = TRUE;
}

void					calc_pointer_count(t_pointer_keeper *keeper)
{
	if (!keeper || !keeper->head)
		return ;
	keeper->attr.pointer_count = 1;
	keeper->current = keeper->head;
	while (keeper->current->next && (keeper->current = keeper->current->next))
		keeper->attr.pointer_count++;
}

t_pointer_keeper_attr	*get_default_pointer_keeper_attr(void)
{
	t_pointer_keeper_attr	*attr;

	if (!(attr =
			(t_pointer_keeper_attr *)malloc(sizeof(t_pointer_keeper_attr))))
		return (NULL);
	init_pointer_keeper_attr(attr);
	return (attr);
}

void					copy_pointer_keeper_attr(
		t_pointer_keeper_attr *source, t_pointer_keeper_attr *target)
{
	if (!source || !target)
		return ;
	target->destroy_added_matrix = source->destroy_added_matrix;
	target->pointer_count = source->pointer_count;
	target->destroy_on_error = source->destroy_on_error;
	target->add_null_ptr = source->add_null_ptr;
	target->destroy_ptr = source->destroy_ptr;
}
