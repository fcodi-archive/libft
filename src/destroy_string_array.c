/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_string_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owl <owl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 07:09:23 by owl               #+#    #+#             */
/*   Updated: 2020/05/15 07:09:51 by owl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string_array.h>

void	destroy_string_array(char **string_array)
{
	size_t		i;

	if (!string_array)
		return ;
	i = 0;
	while (string_array[i])
		free(string_array[i++]);
	free(string_array);
}
