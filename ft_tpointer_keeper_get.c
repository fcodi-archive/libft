/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpointer_keeper_get.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:33:24 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/06 19:06:10 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tpointer_keeper.h"

t_pointer_keeper	*find_tpointer_keeper_by_tag(
		t_pointer_keeper *keeper, char *tag)
{
	t_pointer_keeper	*tag_keeper;
	_Bool 				result;

	if (tag && keeper->head && (tag_keeper = new_tpointer_keeper()))
	{
		result = TRUE;
		keeper->current = keeper->head;
		while (keeper->current)
		{
			if (ft_strstr(keeper->current->tag, tag))
				if (!tag_keeper->add_tag(tag_keeper, keeper->current->ptr, tag))
				{
					result = FALSE;
					break ;
				}
			keeper->current = keeper->current->next;
		}
		if (!result)
			destroy_tpointer_keeper(tag_keeper);
		return (result ? tag_keeper : NULL);
	}
	return (NULL);
}

t_pointer_keeper	*find_tpointer_keeper_by_id(
		t_pointer_keeper *keeper, size_t id)
{
	t_pointer_keeper	*id_keeper;
	_Bool 				result;

	if (!keeper)
		return (NULL);
	if ((keeper->current = keeper->head)
	&& (id_keeper = new_tpointer_keeper()))
	{
		result = TRUE;
		while (keeper->current)
		{
			if (keeper->current->id == id)
				if (!id_keeper->add_id(keeper, keeper->current->ptr, id))
				{
					result = FALSE;
					break ;
				}
			keeper->current = keeper->current->next;
		}
		if (!result)
			destroy_tpointer_keeper(id_keeper);
		return (result ? id_keeper : NULL);
	}
	return (NULL);
}