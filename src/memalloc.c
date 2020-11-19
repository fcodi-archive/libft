/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memfunc.h>

void	*memalloc(const size_t size)
{
	static t_pointer_keeper		*collector = NULL;
	void							*ptr;

	if (!size || (!collector && !(collector = get_garbage_collector()))
		|| !(ptr = malloc(size))
		|| !(collector->add(collector, ptr)))
		return (NULL);
	return (ptr);
}
