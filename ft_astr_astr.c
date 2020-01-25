/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_astr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:29:24 by fcodi             #+#    #+#             */
/*   Updated: 2020/01/25 14:54:03 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

_Bool	ft_astr_astr(char **astr1, char **astr2)
{
	size_t		count;
	size_t		i;
	size_t		j;

	if (!astr1 || !*astr1 || !astr2 || !*astr2)
		return (FALSE);
	i = 0;
	count = 0;
	while (astr1[i])
	{
		j = 0;
		while (astr2[j])
			if (ft_strstr(astr1[i], astr2[j]))
			{
				count++;
				break ;
			}
			else
				j++;
		i++;
	}
	return (ft_astr_len(astr1) == count ? TRUE : FALSE);
}
