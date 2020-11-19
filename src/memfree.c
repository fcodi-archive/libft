/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memfree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memfunc.h>

void	ft_free(void *ptr)
{
	static t_pointer_keeper		*collector = NULL;

	if (!ptr)
		return ;
	if (!collector)
		collector = get_garbage_collector();
	if (ptr == ft_free && collector)
	{
		destroy_pointer_keeper(&collector);
		collector = NULL;
	}
	if (collector)
	{
		destroy_pointer_by_ptr(collector, ptr);
		ptr = NULL;
	}
}
