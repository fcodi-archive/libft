/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpointer_keeper_get.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 15:25:04 by fcodi             #+#    #+#             */
/*   Updated: 2020/01/04 15:25:04 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tpointer_keeper.h"

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
	if (!keeper || !ptr)
		return (NULL);
	if (keeper->head)
	{
		if ((keeper->current = keeper->head)->ptr == ptr)
			return (keeper->current);
		while ((keeper->current = keeper->current->next))
			if (keeper->current->ptr == ptr)
				return (keeper->current);
	}
	return (NULL);
}