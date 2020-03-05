/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:40:38 by fcodi             #+#    #+#             */
/*   Updated: 2020/03/05 19:48:13 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# if (NEED_VANILLA_STDIO || !NO_VANILLA_LIBFT)
#  include <unistd.h>
#  define NEED_BOOLEAN
#  include <ft_bool.h>
#  include <ft_string.h>

void			ft_putstr(const char *str);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(const char *str);

# endif

#endif
