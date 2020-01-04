/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpointer_keeper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:53:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/01/04 15:44:30 by fcodi            ###   ########.fr       */
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
	keeper->convert = convert_tpointer_keeper_to_massive;
	keeper->add_massive = add_tpointer_keeper_massive;
	keeper->destroy_all = destroy_tpointer_all;
	keeper->add_massive = add_tpointer_keeper_massive;
	keeper->get_by_number = get_tpointer_by_number;
	keeper->find_by_ptr = find_tpointer_by_ptr;
	return (keeper);
}