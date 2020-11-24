/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   os.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:17:27 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/24 20:46:17 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OS_H
# define OS_H

# if (defined(_WIN32) || defined(_WIN64))
#  define OS_FAMILY Windows
# elif (defined(__APPLE__) && defined(__MACH__))
#  define OS_FAMILY Apple
# elif (defined(linux) || defined(__linux) || defined(__linux__))
#  define OS_FAMILY Linux
# endif

#endif
