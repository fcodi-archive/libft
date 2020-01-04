/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpointer_keeper_attr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:55:07 by fcodi             #+#    #+#             */
/*   Updated: 2020/01/04 13:55:56 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tpointer_keeper.h"

void	init_tpointer_keeper_attr(t_pointer_keeper_attr *attr)
{
	attr->size = 0;
	attr->free_ptr = FALSE;
	attr->skip_null_ptr = TRUE;
}