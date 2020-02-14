/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tpointer_keeper.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:40:09 by fcodi             #+#    #+#             */
/*   Updated: 2020/02/13 18:04:30 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TPOINTER_KEEPER_H
# define FT_TPOINTER_KEEPER_H
# include "ft_bool.h"
# include "libft.h"
# include <stdlib.h>

typedef struct s_pointer			t_pointer;

struct								s_pointer
{
	size_t							id;
	size_t							number;
	char 							*tag;
	void							*ptr;
	t_pointer						*next;
	t_pointer						*prev;
};

typedef struct						s_pointer_keeper_attr
{
	size_t							size;
	_Bool 							free_ptr;
	_Bool 							skip_null_ptr;
	_Bool 							sort_by_id;
	_Bool 							sort_by_tag;
	_Bool 							find_init_always;
	char 							*find_tag;
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
	_Bool 							(*add_id)(t_pointer_keeper *keeper,
			void *ptr, size_t id);
	_Bool 							(*add_tag)(t_pointer_keeper *keeper,
			void *ptr, char *tag);
	void							**(*convert)(t_pointer_keeper *keeper);
	void							**(*convert_tag)(
			t_pointer_keeper *keeper, char *tag);
	_Bool 							(*add_massive)(t_pointer_keeper *keeper,
			void **massive);
	void							(*destroy_all)(t_pointer_keeper *keeper);
	void							(*destroy_last_count)(
			t_pointer_keeper *keeper, size_t count);
	t_pointer 						*(*find_number)(t_pointer_keeper *keeper,
			size_t number);
	t_pointer						*(*find_ptr)(t_pointer_keeper *keeper,
			void *ptr);
	t_pointer						*(*find_id)(t_pointer_keeper *keeper,
			size_t id);
	t_pointer						*(*find_tag)(t_pointer_keeper *keeper,
			char *tag);
	t_pointer_keeper				*(*find_id_all)(t_pointer_keeper *keeper,
			size_t id);
	t_pointer_keeper				*(*find_tag_all)(t_pointer_keeper *keeper,
			char *tag);
};

void								init_tpointer_keeper_attr(
		t_pointer_keeper_attr *attr);
void								destroy_tpointer(t_pointer *tpointer,
		t_pointer_keeper_attr *attr);
_Bool 								add_tpointer(t_pointer_keeper *keeper,
		void *ptr);
_Bool 								add_tpointer_with_tag(
		t_pointer_keeper *keeper, void *ptr, char *tag);
_Bool 								add_tpointer_with_id(
		t_pointer_keeper *keeper, void *ptr, size_t id);
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
t_pointer							*get_tpointer_by_id(
		t_pointer_keeper *keeper, size_t id);
t_pointer							*find_tpointer_by_tag(
		t_pointer_keeper *keeper, char *tag);
t_pointer_keeper					*find_tpointer_keeper_by_tag(
		t_pointer_keeper *keeper, char *tag);
t_pointer_keeper					*find_tpointer_keeper_by_id(
		t_pointer_keeper *keeper, size_t id);
void		**convert_tpointer_keeper_to_massive_with_tag(
		t_pointer_keeper *keeper, char *tag);


#endif
