/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 22:31:11 by fcodi             #+#    #+#             */
/*   Updated: 2019/10/08 19:59:27 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_astr_put(char **astr)
{
	int		i;

	if (astr && *astr)
	{
		i = -1;
		while (astr[++i])
		{
			ft_putstr(astr[i]);
			ft_putchar('\n');
		}
	}
}
