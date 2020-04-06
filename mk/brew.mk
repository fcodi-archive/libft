.PHONY: default

BREW = $(BREW_BIN_PATH)/brew

BREW_PATH = $(HOME)/.brew

BREW_BIN_PATH = $(BREW_PATH)/bin

BREW_INSTALL = $(PROJECT_PATH)/42homebrewfix/install.sh

GLOBAL = $(BREW_BIN_PATH)/global

GTAGS = $(BREW_BIN_PATH)/gtags

default: all

$(GLOBAL): $(BREW)
	$(BREW) install global

ifeq ($(wildcard $(BREW)),)
$(BREW): $(BREW_INSTALL)
else
$(BREW):
endif

$(BREW_INSTALL):
	if [ ! -d $(dir $(BREW_INSTALL)) ]; \
		then git clone https://github.com/tolsadus/42homebrewfix.git ; fi ;
	sh $@
