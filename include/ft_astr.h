/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_astr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:14:58 by fcodi             #+#    #+#             */
/*   Updated: 2020/03/05 19:33:10 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASTR_H
# define FT_ASTR_H

# if (NEED_VANILLA_ASTR || !NO_VANILLA_LIBFT)
#  include <ft_string.h>

void	ft_astrdel(char **astr, size_t nstr);

# endif

#endif
