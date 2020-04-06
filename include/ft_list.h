/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:45:23 by fcodi             #+#    #+#             */
/*   Updated: 2020/03/05 19:44:27 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# if (NEED_VANILLA_LIST || !NO_VANILLA_LIBFT)
#  include <ft_memfunc.h>
#  include <ft_stddef.h>
#  include <stdlib.h>

void		ft_lstadd(t_list **alst, t_list *new);
void		ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list		*ft_lstnew(const void *content, size_t content_size);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));

# endif

#endif
