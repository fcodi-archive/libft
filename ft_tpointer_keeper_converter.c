/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpointer_keeper_converter.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:48:08 by fcodi             #+#    #+#             */
/*   Updated: 2020/01/04 15:05:04 by fcodi            ###   ########.fr       */
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
	i = 0;
	massive[keeper->attr.size] = NULL;
	keeper->current = keeper->head;
	while (i < keeper->attr.size)
	{
		massive[i++] = keeper->current->ptr;
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