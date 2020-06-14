/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 22:31:11 by fcodi             #+#    #+#             */
/*   Updated: 2020/06/14 17:07:48 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_astr_put(char **astr)
{
	size_t		written_bytes;
	size_t		current_written;
	size_t		i;

	written_bytes = 0;
	if (!astr || !*astr)
		return (written_bytes);
	i = (size_t)-1;
	while (astr[++i])
		if ((current_written = ft_strput(astr[i])) != (size_t)-1)
			written_bytes += current_written;
	return (written_bytes);
}
