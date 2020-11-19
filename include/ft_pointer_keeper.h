/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_keeper.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:40:09 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 00:19:55 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POINTER_KEEPER_H
# define FT_POINTER_KEEPER_H
# include <ft_bool.h>
# include <stdlib.h>
# include <ft_pointer_keeper_structs.h>

_Bool					add_pointer(t_pointer_keeper *keeper, void *ptr);
void					destroy_pointer(t_pointer *pointer);
void					destroy_pointer_current(t_pointer_keeper *keeper);
void					destroy_pointer_all(t_pointer_keeper *keeper);
void					init_pointer_keeper_attr(t_pointer_keeper_attr *attr);
void					destroy_pointer_keeper(t_pointer_keeper **keeper);
void					calc_pointer_count(t_pointer_keeper *keeper);
void					**convert_pointer_keeper_to_matrix(
						t_pointer_keeper *keeper);
t_pointer_keeper		*new_pointer_keeper(void);
t_pointer_keeper		*new_pointer_keeper_with_attr(
						t_pointer_keeper_attr *attr);
t_pointer_keeper_attr	*get_default_pointer_keeper_attr(void);
void					destroy_pointer_with_attr(t_pointer *pointer,
						t_pointer_keeper_attr *attr);
void					destroy_pointer_last_count(t_pointer_keeper *keeper,
												   size_t count);
_Bool					add_matrix_to_keeper(
						t_pointer_keeper *keeper,
						void **matrix);
void					copy_pointer_keeper_attr(
				t_pointer_keeper_attr *source, t_pointer_keeper_attr *target);

t_pointer				*get_pointer_by_ptr(t_pointer_keeper *keeper,
											 void *ptr);
void					destroy_pointer_by_ptr(t_pointer_keeper *keeper,
											   void *ptr);

#endif
