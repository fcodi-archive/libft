/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/06 18:45:36 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memfunc.h>

void	*ft_madd(void *ptr)
{
	static t_garbage_collector	*collector = NULL;

	if (!collector)
		collector = get_garbage_collector();
	if (!get_tpointer_by_ptr(collector, ptr))
		collector->add(collector, ptr);
	return (ptr);
}
