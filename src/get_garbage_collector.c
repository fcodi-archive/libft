/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_garbage_collector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_pointer_keeper.h>

t_pointer_keeper		*get_garbage_collector(void)
{
	static t_pointer_keeper		*collector = NULL;

	if (collector)
		return (collector);
	else if (!(collector = new_pointer_keeper()))
		return (NULL);
	collector->attr.destroy_ptr = TRUE;
	return (collector);
}
