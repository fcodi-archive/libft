/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bool.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:24:16 by fcodi             #+#    #+#             */
/*   Updated: 2020/03/05 19:37:00 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOL_H
# define FT_BOOL_H

# if (NEED_VANILLA_CODITION || !NO_VANILLA_LIBFT)
#  define NEED_BOOLEAN

int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isspace(int c);

# endif

# ifdef NEED_BOOLEAN
#  define FALSE 0
#  define TRUE 1
# endif

#endif
