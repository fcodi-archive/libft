/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_keeper_structs.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:40:09 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINTER_KEEPER_STRUCTS_H
# define FT_POINTER_KEEPER_STRUCTS_H
# include <ft_bool.h>
# include <stdlib.h>

typedef struct s_pointer		t_pointer;

struct							s_pointer
{
	void		*ptr;
	t_pointer	*next;
	t_pointer	*prev;
};

typedef struct					s_pointer_keeper_attr
{
	size_t	pointer_count;
	_Bool	add_null_ptr : 1;
	_Bool	destroy_ptr : 1;
	_Bool	destroy_on_error : 1;
	_Bool	destroy_keeper_after_converting : 1;
	_Bool	ignore_pointer_count_when_destroy : 1;
	_Bool	destroy_added_matrix : 1;
}								t_pointer_keeper_attr;

typedef struct s_pointer_keeper	t_pointer_keeper;

struct							s_pointer_keeper
{
	t_pointer_keeper_attr	attr;
	t_pointer				*head;
	t_pointer				*tail;
	t_pointer				*current;
	t_pointer				*(*find_by_ptr)(t_pointer_keeper *keeper,
							void *ptr);
	void					(*destroy_by_ptr)(t_pointer_keeper *keeper,
							void *ptr);
	_Bool					(*add)(t_pointer_keeper *keeper, void *ptr);
	void					(*destroy)(t_pointer *pointer);
	void					(*destroy_current)(t_pointer_keeper *keeper);
	void					(*destroy_attr)(t_pointer *pointer,
							t_pointer_keeper_attr *attr);
	void					(*destroy_last_count)(t_pointer_keeper *keeper,
							size_t count);
	void					(*destroy_keeper)(t_pointer_keeper **keeper_ptr);
	void					(*destroy_all)(t_pointer_keeper *keeper);
	void					**(*convert)(t_pointer_keeper *keeper);
	_Bool					(*matrix_convert)(t_pointer_keeper *keeper,
							void **matrix);
};

#endif
