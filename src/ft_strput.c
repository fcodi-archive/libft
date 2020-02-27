/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:27:53 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/04 12:28:03 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t		ft_strput(const char *string)
{
	size_t		written_bytes;

	written_bytes = 0;
	if (!string)
		return (written_bytes);
	return (write(STDOUT, string, ft_strlen(string)));
}