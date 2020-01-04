/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:35:58 by fcodi             #+#    #+#             */
/*   Updated: 2020/01/04 15:58:15 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atox_base.h"

unsigned		ft_atou_base(const char *number, const unsigned short base)
{
	return ((unsigned)ft_atollu_base(number, base));
}
