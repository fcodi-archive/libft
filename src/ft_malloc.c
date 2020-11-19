/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:59:23 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memfunc.h>

void	*ft_malloc(const size_t size)
{
	static t_pointer_keeper	*collector = NULL;
	void						*ptr;

	if (!size || !(ptr = malloc(size)))
		return (NULL);
	ft_bzero(ptr, size);
	if ((!collector && !(collector = get_garbage_collector()))
		|| !collector->add(collector, ptr))
	{
		free(ptr);
		ft_exit(rc_garbage_collector, EXIT_MESSAGE);
	}
	return (ptr);
}
