/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolu_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:38:31 by fcodi             #+#    #+#             */
/*   Updated: 2019/10/08 20:39:35 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atox_base.h"

unsigned long	ft_atolu_base(const char *number, const unsigned short base)
{
	return ((unsigned long)ft_atollu_base(number, base));
}