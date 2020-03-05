/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stddef.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:40:19 by fcodi             #+#    #+#             */
/*   Updated: 2020/03/05 20:13:18 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDDEF_H
# define FT_STDDEF_H

# ifdef NEED_UNISTD_H
#  include <unistd.h>
# endif

# if (NEED_VANILLA_TYPEDEF || !NO_VANILLA_LIBFT)
#  include <unistd.h>

typedef struct				s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}							t_list;
# else

typedef __int128 			int128_t;
typedef unsigned __int128	uint128_t;

# endif

# if (NEED_VANILLA_UTILS || !NO_VANILLA_LIBFT)
#  include <unistd.h>
#  define NEED_BOOLEAN
#  include <ft_bool.h>

size_t			ft_uintlen(unsigned int n);

# endif

# ifdef NEED_DEFAULT_FD
#  define STDIN 0
#  define STDOUT 1
#  define STDERR 2
# endif

# ifdef NEED_SPECIAL_SYMBOL_NAMING
#  define NUL '\0'
# endif

# ifdef NEED_BOOLEAN
#  include <ft_bool.h>
# endif

#endif
