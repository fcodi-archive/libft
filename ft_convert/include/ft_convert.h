/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:59:49 by fcodi             #+#    #+#             */
/*   Updated: 2020/03/05 19:56:20 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

# if (NEED_VANILLA_CONVERT || !NO_VANILLA_LIBFT)
#  define NEED_SPECIAL_SYMBOL_NAMING
#  include <ft_stddef.h>
#  include <ft_string.h>
#  include <ft_bool.h>

int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

# endif

#endif
