/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.mk                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:26:51 by fcodi             #+#    #+#             */
/*   Updated: 2020/11/20 14:26:51 by fcodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#TODO Дописать инсталяцию gnu global
#TODO Реализовать поиск зависимостей между исходными и заголовчными файлами

ifndef ($(GLOBAL_MK))
GLOBAL_MK :=

GLOBAL_FTP = https://ftp.gnu.org/pub/gnu/global/



GLOBAL_INSTALL = curl https://ftp.gnu.org/pub/gnu/global/ 2> /dev/null | grep \
-Eo "global[a-zA-Z0-9._-]+\.tar\.gz" | sort -Vtx -k 1,1 | tail -1

endif