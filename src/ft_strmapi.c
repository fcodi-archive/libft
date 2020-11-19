/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:18:09 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	i;

	if (s && f)
	{
		if ((string = ft_strnew(ft_strlen(s))))
		{
			i = 0;
			while (s[i])
			{
				string[i] = (*f)((unsigned int)i, (char)s[i]);
				++i;
			}
		}
	}
	else
		return (NULL);
	return (string);
}
