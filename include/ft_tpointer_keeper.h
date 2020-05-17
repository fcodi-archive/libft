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
# include <stdlib.h>
# include "ft_tpointer_keeper_structs.h"

_Bool					add_tpointer(t_pointer_keeper *keeper, void *ptr);
void					destroy_tpointer(t_pointer *pointer);
void					destroy_tpointer_current(t_pointer_keeper *keeper);
void					destroy_tpointer_all(t_pointer_keeper *keeper);
void					init_tpointer_keeper_attr(t_pointer_keeper_attr *attr);
void					destroy_tpointer_keeper(t_pointer_keeper **keeper);
void					calc_tpointer_count(t_pointer_keeper *keeper);
void					**convert_tpointer_keeper_to_matrix(
						t_pointer_keeper *keeper);
t_pointer_keeper		*new_tpointer_keeper(void);
t_pointer_keeper		*new_tpointer_keeper_with_attr(
						t_pointer_keeper_attr *attr);
t_pointer_keeper_attr	*get_default_tpointer_keeper_attr(void);
void					destroy_tpointer_with_attr(t_pointer *pointer,
						t_pointer_keeper_attr *attr);
void					destroy_tpointer_last_count(t_pointer_keeper *keeper,
						size_t count);
_Bool					add_matrix_to_keeper(
						t_pointer_keeper *keeper,
						void **matrix);
void					copy_tpointer_keeper_attr(
				t_pointer_keeper_attr *source, t_pointer_keeper_attr *target);

t_pointer				*get_tpointer_by_ptr(t_pointer_keeper *keeper,
						void *ptr);
void					destroy_tpointer_by_ptr(t_pointer_keeper *keeper,
						void *ptr);

#endif
