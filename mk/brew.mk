# **************************************************************************** #
#	Brew
# **************************************************************************** #

BREW_DIRECTORY := .brew

ifeq ($(OS),Linux)
LINUXBREW_USER_DIRECTORY := linuxbrew
LINUXBREW_DIRECTORY := .linuxbrew
LINUXBREW_PATH := /home/$(LINUXBREW_USER_DIRECTORY)/$(LINUXBREW_DIRECTORY)
ifeq ($(wildacard $(LINUXBREW_PATH)/bin/brew),)
BREW_PATH := $(HOME)/$(BREW_DIRECTORY)
else
BREW_PATH := $(LINUXBREW_PATH)
endif
else
BREW_PATH := $(HOME)/$(BREW_DIRECTORY)
endif

BREW_BIN_DIRECTORY := bin

BREW_BIN_PATH := $(BREW_PATH)/$(BREW_BIN_DIRECTORY)

BREW_INCLUDE_DIRECTORY := include

BREW_INCLUDE_PATH := $(BREW_PATH)/$(BREW_INCLUDE_DIRECTORY)

BREW_LIBRARY_DIRECTORY := lib

BREW_LIBRARY_PATH := $(BREW_PATH)/$(BREW_LIBRARY_DIRECTORY)

BREW := $(BREW_BIN_PATH)/brew

ifneq ($(CURDIR),$(LIBFT_PATH))
ifneq ($(CURDIR),$(OBJECT_PATH))
INCLUDE_PATH += $(BREW_INCLUDE_PATH)
endif
endif

# **************************************************************************** #
#	Brew install / uninstall variables
# **************************************************************************** #

BREW_INSTALLER_GIT := https://github.com/tolsadus/42homebrewfix.git

BREW_INSTALLER_DIRECTORY := .42homebrewfix

BREW_INSTALLER_PATH := $(HOME)/$(BREW_INSTALLER_DIRECTORY)

BREW_INSTALLER := $(BREW_INSTALLER_PATH)/install.sh

BREW_FIX := $(HOME)/.brew_fix.zsh

ZSHRC := $(HOME)/.zshrc

ZSHRC_BACKUP := $(ZSHRC).backup

SHELLRC := .$(notdir $(SHELL))rc

SHELLRC_BACKUP := $(SHELLRC).backup

BREW_ENV := $(HOME)/.brew_env

BREW_LIB_FT := $(BREW_LIBRARY_PATH)/libft.a

BREW_INCLUDE_FT := $(foreach FILE,$(notdir $(LIBFT_INCLUDE_FILES)), \
	$(addprefix $(BREW_INCLUDE_PATH),$(FILE)))

BREW_LD_LIBRARY_PATH_EXPORT_STRING := \
	"export LD_LIBRARY_PATH=$(BREW_LIBRARY_PATH):$$LD_LIBRARY_PATH"

BREW_INCLUDE_EXPORT_STRING := \
	"export INCLUDE=$(BREW_INCLUDE_PATH):$$INCLUDE"

BREW_CPATH_EXPORT_STRING := \
	"export CPATH=$(BREW_INCLUDE_PATH):$$CPATH"

BREW_BREWFIX_SOURCE_STRING := \
	"source $(BREW_FIX)"

# **************************************************************************** #
#	Brew install / uninstall rules
# **************************************************************************** #

.PHONY: reinstall install install_brew uninstall uninstall_brew

all:

reinstall: uninstall
	$(MAKE) install

install: install_brew
install_brew: $(BREW)
$(BREW)::
ifeq ($(wildcard $(BREW)),)
ifneq ($(wildcard $(SHELLRC)),)
ifneq ($(SHELLRC),$(ZSHRC))
$(BREW):: $(SHELLRC_BACKUP)
endif
endif
ifneq ($(wildcard $(ZSHRC)),)
$(BREW):: $(ZSHRC_BACKUP)
endif
$(BREW):: $(BREW_INSTALLER)
	$(SHELL) $(BREW_INSTALLER)
	$(SHELL) $(BREW) update && $(SHELL) $(BREW) doctor
$(BREW):: $(BREW_ENV)
endif
$(BREW_INSTALLER)::
ifeq ($(wildcard $(BREW_INSTALLER)),)
$(BREW_INSTALLER)::
	git clone $(BREW_INSTALLER_GIT) $(BREW_INSTALLER_PATH)
endif

uninstall: uninstall_brew
uninstall_brew::
	$(RM) $(BREW_FIX) $(ZSHRC) $(SHELLRC) $(BREW_ENV)
	$(RMDIR) $(BREW_PATH) $(dir $(BREW_INSTALLER))
ifneq ($(wildcard $(ZSHRC_BACKUP)),)
uninstall_brew::
	mv $(ZSHRC_BACKUP) $(ZSHRC)
endif
ifneq ($(wildcard $(SHELLRC_BACKUP)),)
ifneq ($(SHELLRC),$(ZSHRC))
uninstall_brew::
	mv $(SHELLRC_BACKUP) $(SHELLRC)
endif
endif

$(BREW_ENV)::
	@echo $(BREW_LD_LIBRARY_PATH_EXPORT_STRING) >> $(BREW_FIX)
	@echo $(BREW_INCLUDE_EXPORT_STRING) >> $(BREW_FIX)
	@echo $(BREW_CPATH_EXPORT_STRING) >> $(BREW_FIX)
ifneq ($(SHELLRC),$(ZSHRC))
$(BREW_ENV)::
	@echo $(BREW_BREWFIX_SOURCE_STRING) >> $(SHELLRC)
endif
$(BREW_ENV)::
	@touch $@

%.backup:
	-cp $(basename $@) $@

# **************************************************************************** #
#	GNU Global
# **************************************************************************** #

GLOBAL ?= $(BREW_BIN_PATH)/global

GTAGS ?= $(BREW_BIN_PATH)/gtags

GTAGS_FILES ?= $(addprefix $(PROJECT_PATH)/,GPATH GTAGS GRTAGS)

.PHONY: clean_gtags

clean: clean_gtags

clean_gtags::
ifneq ($(wildcard $(GTAGS_FILES)),)
clean_gtags::
	$(RM) $(GTAGS_FILES)
endif

$(GTAGS): $(GLOBAL)

ifeq ($(wildcard $(GLOBAL)),)
$(GLOBAL): $(BREW)
	$(shell $(BREW) install global)
else
$(GLOBAL): $(GTAGS_FILES)
$(GTAGS_FILES):
	$(GTAGS)
endif

# **************************************************************************** #
#	SDL
# **************************************************************************** #

LIBSDL2 = $(BREW_LIBRARY_PATH)/libSDL2.a

$(LIBSDL2):: $(BREW)
ifeq ($(OS),Linux)
ifeq ($(shell ldconfig -p | grep $(notdir $(LIBSDL2))),)
$(LIBSDL2)::
	$(eval override LDFLAGS += -lSDL2)
else
$(LIBSDL2)::
	$(SHELL) $(BREW) install SDL2
	$(eval LIBRARY_FILES += $(LIBSDL2))
endif
endif
ifeq ($(OS),Darwin)
$(LIBSDL2)::
	$(SHELL) $(BREW) install SDL2
	$(eval LIBRARY_FILES += $(LIBSDL2))
endif