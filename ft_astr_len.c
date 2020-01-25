/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:30:06 by fcodi             #+#    #+#             */
/*   Updated: 2020/01/25 14:54:03 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_astr_len count number of strings in array of strings and return it
*/

size_t	ft_astr_len(char **astr)
{
	size_t	size;

	size = 0;
	if (!astr || !*astr)
		return (size);
	while (astr[size])
		size++;
	return (size);
}
