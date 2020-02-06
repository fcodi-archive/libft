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
	if (!keeper)
		return ;
	if (keeper->tail)
	{
		keeper->current = keeper->tail;
		while (keeper->current->prev && (keeper->current =
				keeper->current->prev))
			destroy_tpointer(keeper->current->next, &keeper->attr);
		destroy_tpointer(keeper->current, &keeper->attr);
	}
}

void				destroy_tpointer_last_count(t_pointer_keeper *keeper,
		size_t count)
{
	size_t		i;

	if (!keeper || count == 0)
		return ;
	i = 0;
	if (keeper->tail)
	{
		keeper->current = keeper->tail;
		while (i < count && keeper->current->prev && (keeper->current =
				keeper->current->prev))
		{
			destroy_tpointer(keeper->current->next, &keeper->attr);
			i++;
		}
		destroy_tpointer(keeper->current, &keeper->attr);
	}
}

void				destroy_tpointer_keeper(t_pointer_keeper *keeper)
{
	if (!keeper)
		return ;
	destroy_tpointer_all(keeper);
	free(keeper);
}

t_pointer_keeper	*new_tpointer_keeper(void)
{
	t_pointer_keeper	*keeper;

	if (!(keeper = (t_pointer_keeper *)malloc(sizeof(t_pointer_keeper))))
		return (NULL);
	keeper->head = NULL;
	keeper->tail = NULL;
	keeper->current = NULL;
	init_tpointer_keeper_attr(&keeper->attr);
	keeper->add = add_tpointer;
	keeper->add_id = add_tpointer_with_id;
	keeper->add_tag = add_tpointer_with_tag;
	keeper->convert = convert_tpointer_keeper_to_massive;
	keeper->add_massive = add_tpointer_keeper_massive;
	keeper->destroy_all = destroy_tpointer_all;
	keeper->add_massive = add_tpointer_keeper_massive;
	keeper->find_number = get_tpointer_by_number;
	keeper->find_ptr = find_tpointer_by_ptr;
	keeper->find_tag = find_tpointer_by_tag;
	keeper->find_id = get_tpointer_by_id;
	keeper->find_id_all = find_tpointer_keeper_by_id;
	keeper->find_tag_all = find_tpointer_keeper_by_tag;
	keeper->convert_tag = convert_tpointer_keeper_to_massive_with_tag;
	return (keeper);
}