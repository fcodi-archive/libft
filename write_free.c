/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:46:39 by fcodi             #+#    #+#             */
/*   Updated: 2020/01/08 16:50:20 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 		write_free(int fd, char *string, size_t size)
{
	int 	result;

	result = write(fd, string, size);
	string ? free(string) : FALSE;
	return (result);
}
