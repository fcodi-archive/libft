/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:35:58 by fcodi             #+#    #+#             */
/*   Updated: 2020/06/14 17:07:48 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_atox.h>

unsigned		ft_atou_base(const char *number, const unsigned short base)
{
	return ((unsigned)ft_atollu_base(number, base));
}
