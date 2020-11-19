/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfunc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 10:03:51 by bbear             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMFUNC_H
# define FT_MEMFUNC_H

# include <stdlib.h>
# include <ft_pointer_keeper_structs.h>
# include <libft.h>
# define EXIT_MESSAGE __PRETTY_FUNCTION__
# define RC_OK ""
# define RC_ERROR "Unspecified error"
# define RC_ALLOCATION_FAIL "Memory allocation fail"
# define RC_GARBAGE_COLLECTOR "Garbage collector error"
# define RC_SDL_INITIALIZE_FAIL "Initialize fail"

typedef enum	e_return_code
{
	rc_ok,
	rc_error,
	rc_allocation_fail,
	rc_garbage_collector,
	rc_initialize_fail
}				t_return_code;

t_pointer_keeper	*get_garbage_collector(void);
void	ft_exit(const int code, const char *message);
void	*ft_calloc(const size_t nmemb, const size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_malloc(const size_t size);
void	*ft_madd(void *ptr);
void	ft_free(void *ptr);

#endif
