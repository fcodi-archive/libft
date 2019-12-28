/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:39:17 by fcodi             #+#    #+#             */
/*   Updated: 2019/10/10 15:01:52 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GARBAGEVENT_COLLECTOR_H

/*
** ************************************************************************** **
** Define
** ************************************************************************** **
*/

# define FT_GARBAGEVENT_COLLECTOR_H
# ifndef GC_FAIL_
#  define GC_FAIL_ACTION GC_ALL
#  define GC_PARENT 1
#  define GC_ALL 2
#  define GC_ERROR_MALLOC -5
# endif
# ifndef LOGICAL
#  define LOGICAL
#  define TRUE 1
#  define FALSE 0
#  define ERROR -1
#  define OK 0
# endif

/*
** ************************************************************************** **
** Include
** ************************************************************************** **
*/

# include <stdlib.h>

/*
** ************************************************************************** **
** Structs and typedefs
** ************************************************************************** **
*/

typedef struct s_collector				t_collector;
typedef struct s_parray					t_parray;

t_collector								*g_collector;

struct									s_collector
{
	t_parray							*head;
	t_parray							*tail;
	t_parray							*current;
};

struct									s_parray
{
	void								*ptr;
	_Bool								have_childs;
	t_parray							*parent;
	t_parray							*next;
	t_parray							*prev;
};

/*
** ************************************************************************** **
** Functions
** ************************************************************************** **
*/

__attribute__ ((constructor)) _Bool		init_collector(void);
void									delete(void *ptr);
void									*new(void *ptr);
void									*fnew(void *ptr, void *parent_ptr);
__attribute__ ((destructor)) void		destroy_collector(void);
void									gc_del_parray_all(void);
void									gc_del_parray(t_parray *current);
void									gc_destroy_childhood(t_parray *parent);
t_parray								*gc_new_parray(void);
t_parray								*gc_get_parray_by_ptr(void *ptr);
t_parray								*gc_get_parray_by_parent
(t_parray *parent, _Bool first);

#endif
