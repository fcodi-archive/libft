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

all:

include $(MK)/function.mk

# **************************************************************************** #
#	Variable
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

BREW = $(BREW_BIN)/brew

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

# **************************************************************************** #
#	Brew dependency
# **************************************************************************** #

include $(MK)/which.mk

all: $(BREW_DEPENDENCY)

$(BREW_DEPENDENCY):: $(WHICH)
	-@$(WHICH) $@ 1>/dev/null 2>/dev/null && exit\
	|| $(BREW) info $@ 1>/dev/null || exit\
	&& $(BREW) info $@ | grep "From:" | grep "Formula" 1>/dev/null\
	&& $(BREW) install $@ && exit\
	|| $(BREW) info $@ | grep "From:" | grep "Casks" 1>/dev/null\
	&& $(BREW) cask install $@ && exit\
	|| echo "Undefined type of brew element $@"

endif