#* ************************************************************************** */
#*                                                                            */
#*                                                        :::      ::::::::   */
#*   brew.mk                                            :+:      :+:    :+:   */
#*                                                    +:+ +:+         +:+     */
#*   By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+        */
#*                                                +#+#+#+#+#+   +#+           */
#*   Created: 2020/11/22 16:21:41 by fcodi             #+#    #+#             */
#*   Updated: 2020/11/22 16:21:41 by fcodi            ###   ########.fr       */
#*                                                                            */
#* ************************************************************************** */

ifndef BREW_MK
BREW_MK := $(MK)/brew.mk

include $(MK)/function.mk

# **************************************************************************** #
#	Environment variables
# **************************************************************************** #

BREW_DIRECTORY = .brew

BREW_PATH = $(HOME)/$(BREW_DIRECTORY)

BREW_PATH_EXIST = $(BREW_PATH_EXIST)

BREW_PREFIX = $(BREW_PATH)

BREW_BIN = $(BREW_PATH)/bin

BREW_SBIN = $(BREW_PATH)/sbin

BREW_INCLUDE = $(BREW_PATH)/include

BREW_LIB = $(BREW_PATH)/lib

BREW_VAR = $(BREW_PATH)/var

BREW_OPT = $(BREW_PATH)/opt

BREW_SHARE = $(BREW_PATH)/share

BREW_MAN = $(BREW_PATH)/manpages

BREW_ETC = $(BREW_PATH)/etc

BREW_DOC = $(BREW_PATH)/docs

BREW_CELLAR = $(BREW_PATH)/Cellar

BREW = $(BREW_BIN)/_brew

# **************************************************************************** #
#	Configure
# **************************************************************************** #

CONFIGURE_FLAGS = --prefix="$(BREW_PREFIX)" --exec-prefix="$(BREW_PREFIX)" \
	--oldincludedir="$(BREW_INCLUDE)" --datarootdir="$(BREW_SHARE)"

_CONFIGURE = cd $1; ./configure $(CONFIGURE_FLAGS)

_CONFIGURE_WITH_FLAGS = $(_CONFIGURE) $2

# **************************************************************************** #
#	Brew install
# **************************************************************************** #

#TODO Проверить установку на Ubuntu
#include $(MK)/os.mk

BREW_INSTALL_SH_URL = \
	https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh

.PHONY: install uninstall reinstall

install: $(BREW)
ifeq ($(wildcard $(BREW)),)
$(BREW):
	+@curl -fsSL $(BREW_INSTALL_SH_URL) | $(SHELL)
	$(BREW) update
	$(BREW) upgrade
endif

reinstall: uninstall install

ifeq ($(MAKECMDGOALS),uninstall)
UNINSTALL_LIST += $(BREW_PATH)
endif

endif