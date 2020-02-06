/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpointer_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:32:54 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/06 19:14:57 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tpointer_keeper.h"

t_pointer		*get_tpointer_by_id(t_pointer_keeper *keeper, size_t id)
{
	static size_t 		number = 0;

	if (!keeper && !id)
		number = 0;
	if (keeper && keeper->head)
	{
		if (keeper->attr.find_init_always
		&& (keeper->current = keeper->head)->id == id)
			return (keeper->current);
		else
			keeper->current = keeper->current->next;
		while (keeper->current && keeper->current->id != id)
			keeper->current = keeper->current->next;
		if (!keeper->current)
			number = 0;
		else
			number = keeper->current->number;
		return (keeper->current);
	}
	return (NULL);
}

t_pointer 		*get_tpointer_by_number(t_pointer_keeper *keeper,
		size_t number)
{
	size_t		i;

	if (!keeper)
		return (NULL);
	i = 0;
	if (keeper->head)
	{
		keeper->current = keeper->head;
		while (i < number && (keeper->current = keeper->current->next))
			i++;
		return (keeper->current);
	}
	return (NULL);
}

t_pointer		*find_tpointer_by_ptr(t_pointer_keeper *keeper, void *ptr)
{
	static size_t 		number = 0;

	if (!keeper && !ptr)
		number = 0;
	if (keeper && keeper->head)
	{
		if (keeper->attr.find_init_always
		&& (keeper->current = keeper->head)->ptr == ptr)
			return (keeper->current);
		else
			keeper->current = keeper->current->next;
		while ((keeper->current = keeper->current->next))
			if (keeper->current->ptr == ptr)
			{
				number = keeper->current->number;
				return (keeper->current);
			}
		if (!keeper->current)
			number = 0;
	}
	return (NULL);
}

t_pointer		*find_tpointer_by_tag(
		t_pointer_keeper *keeper, char *tag)
{
	static size_t		number = 0;

	if (!keeper && !tag)
		number = 0;
	else if (keeper && keeper->head)
	{
		if (keeper->attr.find_init_always)
			keeper->current = keeper->head;
		else
			keeper->current = keeper->current->next;
		while (keeper->current)
			if (ft_strstr(keeper->current->tag, tag))
			{
				number = keeper->current->number + 1;
				return (keeper->current);
			}
			else
				keeper->current = keeper->current->next;
		if (!keeper->current)
			number = 0;
	}
	return (NULL);
}