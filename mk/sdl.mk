include $(LIBFT_MK_PATH)/sdl-vars.mk

include $(LIBFT_MK_PATH)/brew.mk

.PHONY: default

.INTERMEDIATE: $(SDL_SRC_PATH)

default: all

$(MAKE_SDL): $(SDL_BUILD_MAKEFILE)
	$(MAKE) --makefile=$(SDL_BUILD_MAKEFILE) \
	--directory=$(SDL_BUILD_PATH) all install
	$(RMDIR) $(SDL_SRC_PATH) $(SDL_PREBUILD_PATH)

$(SDL_BUILD_MAKEFILE): $(SDL_BUILD_PATH)

$(SDL_BUILD_PATH)::
	@if [ ! -d $(SDL_BUILD_PATH) ]; then mkdir $(SDL_BUILD_PATH); fi;
$(SDL_BUILD_PATH):: $(SDL_SRC_PATH)

$(SDL_SRC_PATH): $(HG)
	$(HG) clone $(LIBSDL_HG) $(SDL_SRC_PATH)
	$(SDL_BUILD_CONFIGURE)
