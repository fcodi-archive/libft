/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:18:57 by fcodi             #+#    #+#             */
/*   Updated: 2020/03/05 20:10:20 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** ************************************************************************** **
** Vanilla
** ************************************************************************** **
*/

# if (NEED_VANILLA_STRING || !NO_VANILLA_LIBFT)
#  include <ft_string.h>
# endif
# if (NEED_VANILLA_STDIO || !NO_VANILLA_LIBFT)
#  include <ft_stdio.h>
# endif
# if (NEED_VANILLA_LIST || !NO_VANILLA_LIBFT)
#  include <ft_list.h>
# endif
# if (NEED_VANILLA_MEMFUNC || !NO_VANILLA_LIBFT)
#  include <ft_memfunc.h>
# endif
# if (NEED_VANILLA_CODITION || !NO_VANILLA_LIBFT)
#  include <ft_bool.h>
# endif
# if (NEED_VANILLA_TYPEDEF || !NO_VANILLA_LIBFT)
#  include <ft_stddef.h>
# endif
# if (NEED_VANILLA_CONVERT || !NO_VANILLA_LIBFT)
#  include <ft_convert.h>
# endif
# if (NEED_VANILLA_ASTR || !NO_VANILLA_LIBFT)
#  include <ft_astr/include/ft_astr.h>
# endif
# ifndef NO_VANILLA_LIBFT


# endif

#endif
