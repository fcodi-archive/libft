.PHONY: default uninstall_brew install_brew

include $(LIBFT_MK_PATH)/brew-vars.mk

VPATH = $(BREW_BIN_PATH):$(BREW_SBIN_PATH):$(BREW_INCLUDE_PATH)\
	:$(BREW_LIB_PATH):$(BREW_ETC_PATH):$(BREW_SHARE_PATH)\
	:$(BREW_VAR_PATH):$(BREW_OPT_PATH)

default: all

install_brew:: 
.PHONY: $(BREW_INSTALLER)
install_brew:: $(BREW_INSTALLER)

ifeq ($(wildcard $(BREW)),)
$(BREW): $(BREW_INSTALLER)
	sh $(BREW_INSTALLER)
	$(RMDIR) $(BREW_INSTALLER_PATH)
endif

$(BREW_INSTALLER):
	git clone $(HOMEBREWFIX_GIT) $(BREW_INSTALLER_PATH)

$(RUBY): $(BREW)
	$(BREW) install ruby

uninstall_brew: $(RUBY)
	$(shell $(RUBY) -e $(BREW_UNINSTALLER_RUBY_COMMAND))
	$(RMDIR) $(BREW_PATH)

$(HG): $(BREW)
	$(BREW) install mercurial
