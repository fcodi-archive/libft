/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:32:24 by fcodi             #+#    #+#             */
/*   Updated: 2019/12/18 21:52:15 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_astr_tolower check char is upper, and when its true change case to lower
** and write result in array of strings (char **astr)
*/

_Bool	ft_astr_tolower(char **astr)
{
	size_t		i;
	size_t		n;

	if (!astr || !*astr)
		return (FALSE);
	n = 0;
	while (astr[n])
	{
		i = 0;
		while (astr[n][i])
			if (ft_isupper(astr[n][i]))
				astr[n][i] = (char)ft_tolower(astr[n][i]);
			else
				i++;
		n++;
	}
	return (TRUE);
}