/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpointer_keeper.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:40:09 by fcodi             #+#    #+#             */
/*   Updated: 2020/01/04 15:23:41 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TPOINTER_KEEPER_H
# define FT_TPOINTER_KEEPER_H
# include "ft_bool.h"
# include <stdlib.h>

typedef struct s_pointer			t_pointer;

struct								s_pointer
{
	void							*ptr;
	t_pointer						*next;
	t_pointer						*prev;
};

typedef struct						s_pointer_keeper_attr
{
	size_t							size;
	_Bool 							free_ptr;
	_Bool 							skip_null_ptr;
}									t_pointer_keeper_attr;

typedef struct s_pointer_keeper		t_pointer_keeper;

struct								s_pointer_keeper
{
	t_pointer 						*head;
	t_pointer						*tail;
	t_pointer 						*current;
	t_pointer_keeper_attr			attr;
	_Bool 							(*add)(t_pointer_keeper *keeper,
			void *ptr);
	void							**(*convert)(t_pointer_keeper *keeper);
	_Bool 							(*add_massive)(t_pointer_keeper *keeper,
			void **massive);
	void							(*destroy_all)(t_pointer_keeper *keeper);
	void							(*destroy_last_count)(
			t_pointer_keeper *keeper, size_t count);
	t_pointer 						*(*get_by_number)(t_pointer_keeper *keeper,
			size_t number);
	t_pointer 						*(*find_by_ptr)(t_pointer_keeper *keeper,
			void *ptr);
};

void								init_tpointer_keeper_attr(
		t_pointer_keeper_attr *attr);
void								destroy_tpointer(t_pointer *tpointer,
		t_pointer_keeper_attr *attr);
_Bool 								add_tpointer(t_pointer_keeper *keeper,
		void *ptr);
void								destroy_tpointer_all(
		t_pointer_keeper *keeper);
void								destroy_tpointer_keeper(
		t_pointer_keeper *keeper);
t_pointer_keeper					*new_tpointer_keeper(void);
void								**convert_tpointer_keeper_to_massive(
		t_pointer_keeper *keeper);
void								destroy_tpointer_last_count(
		t_pointer_keeper *keeper, size_t count);
_Bool 								add_tpointer_keeper_massive(
		t_pointer_keeper *keeper, void **massive);
t_pointer 							*get_tpointer_by_number(
		t_pointer_keeper *keeper, size_t number);
t_pointer							*find_tpointer_by_ptr(
		t_pointer_keeper *keeper, void *ptr);

#endif
