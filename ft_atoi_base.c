/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:26:12 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/29 13:45:11 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atox_base.h"

int		ft_atoi_base(const char *number, const unsigned short base)
{
	return ((int)ft_atoll_base(number, base));
}
