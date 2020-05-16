/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_garbage_collector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:42:21 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/06 18:45:36 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_garbage_collector.h>

t_garbage_collector		*get_garbage_collector(void)
{
	static t_garbage_collector		*collector = NULL;

	if (collector)
		return (collector);
	else if (!(collector = (t_garbage_collector *)new_tpointer_keeper()))
		return (NULL);
	collector->attr.destroy_ptr = TRUE;
	return (collector);
}
