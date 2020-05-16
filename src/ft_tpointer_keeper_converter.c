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

#include <ft_tpointer_keeper.h>

void	**convert_tpointer_keeper_to_matrix(t_pointer_keeper *keeper)
{
	char		**matrix;
	size_t		i;

	matrix = NULL;
	if (!keeper)
		return (NULL);
	if (!keeper->attr.destroy_ptr)
	{
		calc_tpointer_count(keeper);
		if (!keeper->head || !(matrix = (char **)malloc(sizeof(char *)
				* (keeper->attr.pointer_count + 1))))
		{
			keeper->attr.destroy_ptr = TRUE;
			destroy_tpointer_keeper(&keeper);
			return (NULL);
		}
		i = 1;
		matrix[keeper->attr.pointer_count] = NULL;
		*matrix = keeper->head->ptr;
		keeper->current = keeper->head;
		while (keeper->current->next && (keeper->current = keeper->current->next))
			matrix[i++] = keeper->current->ptr;
	}
	if (keeper->attr.destroy_keeper_after_converting)
		keeper->destroy_keeper(&keeper);
	return ((void **)matrix);
}

_Bool	add_matrix_to_tpointer_array(t_pointer_keeper *keeper, void **matrix)
{
	size_t		i;

	if (!keeper || !matrix)
		return (FALSE);
	i = (size_t)-1;
	while (matrix[++i])
		if (!add_tpointer(keeper, matrix[i]))
		{
			if (keeper->attr.destroy_on_error)
				destroy_tpointer_last_count(keeper, i + 1);
			return (FALSE);
		}
	return (TRUE);
}
