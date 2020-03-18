include $(LIBFT_MK_PATH)/brew.mk

include $(LIBFT_MK_PATH)/sdl-vars.mk

.PHONY: default

default: all

ifeq ($(wildcard $(MAKE_SDL)),)
$(MAKE_SDL): $(BREW) $(BREW_FIX_ZSH_BACKUP)
	@if [ ! -f $(MAKE_SDL) ]; then $(BREW) install sdl2; fi
	@echo $$SDL_FIX >> $(BREW_FIX_ZSH)
else
$(MAKE_SDL):
	@echo SDL already prepared
endif

$(BREW_FIX_ZSH_BACKUP):
	cp $(BREW_FIX_ZSH) $(BREW_FIX_ZSH_BACKUP)
