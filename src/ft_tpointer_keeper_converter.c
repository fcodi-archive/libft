/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpointer_keeper_converter.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:48:08 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/06 19:18:24 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tpointer_keeper.h"

void		**convert_tpointer_keeper_to_massive(t_pointer_keeper *keeper)
{
	void	**massive;
	size_t	i;

	if (!keeper || !(massive = (void **)malloc(sizeof(void *)
			* (keeper->attr.size + 1))))
		return (NULL);
	i = -1;
	massive[keeper->attr.size] = NULL;
	keeper->current = keeper->head;
	while (++i < keeper->attr.size)
	{
		if (keeper->attr.sort_by_id)
			massive[i] = keeper->find_id(keeper, i)->ptr;
		else if (keeper->attr.sort_by_tag)
			massive[i] = keeper->find_tag(keeper, keeper->attr.find_tag)->ptr;
		else
			massive[i] = keeper->current->ptr;
		keeper->current = keeper->current->next;
	}
	return (massive);
}

_Bool 		add_tpointer_keeper_massive(t_pointer_keeper *keeper,
		void **massive)
{
	size_t		i;

	if (!keeper || (keeper->attr.skip_null_ptr && (!massive || !*massive)))
		return (FALSE);
	i = 0;
	while (massive[i])
	{
		if (!keeper->add(keeper, massive[i]))
		{
			destroy_tpointer_last_count(keeper, i);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void		**convert_tpointer_keeper_to_massive_with_tag(
		t_pointer_keeper *keeper, char *tag)
{
	if (!keeper || !tag)
		return (NULL);
	keeper->attr.find_tag = tag;
	return (convert_tpointer_keeper_to_massive(keeper));
}