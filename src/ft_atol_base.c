/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:37:19 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/03 08:49:14 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atox_base.h"

long	ft_atol_base(const char *number, const unsigned short base)
{
	return ((long)ft_atoll_base(number, base));
}