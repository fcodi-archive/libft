/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memfunc.h>

void	*ft_madd(void *ptr)
{
	static t_pointer_keeper	*collector = NULL;

	if (!collector)
		collector = get_garbage_collector();
	if (!get_pointer_by_ptr(collector, ptr))
		collector->add(collector, ptr);
	return (ptr);
}
