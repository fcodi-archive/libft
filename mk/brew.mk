# **************************************************************************** #
#	Brew
# **************************************************************************** #

BREW_DIRECTORY ?= .brew

BREW_PATH ?= $(HOME)/$(BREW_DIRECTORY)

BREW_BIN_DIRECTORY ?= bin

BREW_BIN_PATH ?= $(BREW_PATH)/$(BREW_BIN_DIRECTORY)

BREW_INCLUDE_DIRECTORY ?= include

BREW_INCLUDE_PATH ?= $(BREW_PATH)/$(BREW_INCLUDE_DIRECTORY)

BREW_LIBRARY_DIRECTORY ?= lib

BREW_LIBRARY_PATH ?= $(BREW_PATH)/$(BREW_LIBRARY_DIRECTORY)

ifneq ($(CURDIR),$(LIBFT_PATH))
ifneq ($(CURDIR),$(OBJECT_PATH))
INCLUDE_PATH += $(BREW_INCLUDE_PATH)
endif
endif

# **************************************************************************** #
#	Brew install / uninstall
# **************************************************************************** #

BREW_INSTALLER_GIT ?= https://github.com/tolsadus/42homebrewfix.git

BREW_INSTALLER_DIRECTORY ?= .42homebrewfix

BREW_INSTALLER_PATH ?= $(HOME)/$(BREW_INSTALLER_DIRECTORY)

BREW_INSTALLER ?= $(BREW_INSTALLER_PATH)/install.sh

BREW_FIX ?= $(HOME)/.brew_fix.zsh

BASHRC ?= $(HOME)/.bashrc

BASHRC_BACKUP ?= $(BASHRC).backup

ZSHRC ?= $(HOME)/.zshrc

ZSHRC_BACKUP ?= $(ZSHRC).backup

BREW_ENV ?= $(HOME)/.brew_env

BREW_LIB_FT ?= $(BREW_LIBRARY_PATH)/libft.a

BREW_INCLUDE_FT ?= $(foreach FILE,$(notdir $(LIBFT_INCLUDE_FILES)), \
	$(addprefix $(BREW_INCLUDE_PATH),$(FILE)))

.PHONY: default install install_brew uninstall uninstall_brew \
	install_libft uninstall_libft

all:

ifeq ($(wildcard $(BREW)),)
install: install_brew $(BREW_LIBFT)
install_brew: $(BREW)
$(BREW): $(ZSHRC_BACKUP) $(BASHRC_BACKUP)
$(BREW): $(BREW_INSTALLER)
	sh $^
$(BREW): $(BREW_ENV)
install_libft: $(BREW_LIB_FT)
$(BREW_LIB_FT): $(BREW_INCLUDE_FT)
	@$(MAKE) -C $(LIBFT_PATH) all NAME="$(BREW_LIB_FT)"
$(BREW_INCLUDE_FT):
	cp $(addprefix $(LIBFT_INCLUDE_PATH),$(@F)) $@
else
uninstall: uninstall_brew
uninstall_brew:
	$(RM) $(BREW_FIX) $(ZSHRC) $(BASHRC)
	-$(MV) $(ZSHRC_BACKUP) $(ZSHRC)
	-$(MV) $(BASHRC_BACKUP) $(BASHRC)
	$(RMDIR) $(BREW_PATH)
uninstall_libft:
	$(RM) $(BREW_LIB_FT) $(BREW_INCLUDE_FT)
endif

BREW_LD_LIBRARY_PATH_EXPORT_STRING = \
	"export LD_LIBRARY_PATH=$(BREW_LIB_PATH):$$LD_LIBRARY_PATH"

BREW_INCLUDE_EXPORT_STRING = \
	"export INCLUDE=$(BREW_INCLUDE_PATH):$$INCLUDE"

BREW_CPATH_EXPORT_STRING = \
	"export CPATH=$(BREW_INCLUDE_PATH):$$CPATH)"

BREW_BREWFIX_SOURCE_STRING = \
	"source $(BREW_FIX)"

$(BREW_ENV):
	@echo $(BREW_LD_LIBRARY_PATH_EXPORT_STRING) >> $(BREWFIX)
	@echo $(BREW_INCLUDE_EXPORT_STRING) >> $(BREWFIX)
	@echo $(BREW_CPATH_EXPORT_STRING) >> $(BREWFIX)
	@echo $(BREWFIX_SOURCE_STRING) >> $(BASHRC)
	@touch $@
	$(info Restart terminal to apply changes)

%.backup:
	-cp $(basename $@) $@

$(BREW_INSTALLER):
	git clone $(BREW_INSTALLER_GIT) $(BREW_INSTALLER_PATH)

# **************************************************************************** #
#	GNU Global
# **************************************************************************** #

GLOBAL ?= $(BREW_BIN_PATH)/global

GTAGS ?= $(BREW_BIN_PATH)/gtags

GTAGS_FILES ?= $(addprefix $(PROJECT_PATH)/,GPATH GTAGS GRTAGS)

.PHONY: clean_gtags

clean: clean_gtags

clean_gtags:
	$(RM) $(GTAGS_FILES)

$(GTAGS): $(GLOBAL)

ifeq ($(wildcard $(GLOBAL)),)
$(GLOBAL): $(BREW)
	$^ install global
else
$(GLOBAL): $(GTAGS_FILES)
$(GTAGS_FILES):
	$(GTAGS)
endif

# **************************************************************************** #
#	SDL
# **************************************************************************** #

LIBSDL = $(BREW_LIBRARY_PATH)/libSDL.a

$(LIBSDL)::
	$(eval LIBRARY_FILES += $(LIBSDL))
ifeq ($(wildcard $(LIBSDL)),)
$(LIBSDL):: $(BREW)
	$^ install SDL
endif

LIBSDL2 = $(BREW_LIBRARY_PATH)/libSDL2.a

$(LIBSDL2)::
	$(eval LIBRARY_FILES += $(LIBSDL2))
ifeq ($(wildcard $(LIBSDL2)),)
$(LIBSDL2):: $(BREW)
	brew install SDL2
endif