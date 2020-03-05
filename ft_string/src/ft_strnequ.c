/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:11:37 by fcodi             #+#    #+#             */
/*   Updated: 2019/04/27 20:15:07 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

int		ft_strnequ(char const *s1, const char *s2, size_t n)
{
	if (s1 && s2)
		if (ft_strncmp(s1, s2, n) == 0)
			return (TRUE);
	return (FALSE);
}
