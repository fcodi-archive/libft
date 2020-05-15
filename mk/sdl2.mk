# **************************************************************************** #
#	Variables
# **************************************************************************** #

# Make correct clean lib directory (without remove any non SDL2 files)

# Create brew.mk and make install SDL2 with brew
# (or clone from mercurial repository)

# Install shell script to run $: env RTv1 with modified environment

include $(LOG_MK)
include $(BIN_MK)

SDL2_TAR_GZ = $(PROJECT_PATH)/SDL2-2.0.12.tar.gz

SDL2_DIRECTORY = SDL2-2.0.12

SDL2_PATH = $(PROJECT_PATH)/$(SDL2_DIRECTORY)

SDL2_BUILD_PATH = $(SDL2_PATH)/build

SDL2_BUILD_PATH_EXIST = $(SDL2_BUILD_PATH)/.exist

SDL2_CONFIGURE = $(SDL2_PATH)/configure

SDL2_BUILD_PATH = $(SDL2_PATH)/build

SDL2_BUILD_PATH_EXIST = $(SDL2_BUILD_PATH)/.exist

SDL2_BUILD_MAKEFILE = $(SDL2_BUILD_PATH)/Makefile

SDL2_INCLUDE = $(INCLUDE_PATH)/SDL2

SDL2_ERROR_LOG = $(LOG_PATH)/sdl2_build_error.log

SDL2_CONFIG = $(BINNARY_PATH)/sdl2-config

LIBSDL2 = $(PROJECT_PATH)/lib/libSDL2.a

# **************************************************************************** #
#	Rules
# **************************************************************************** #

.PHONY: clean_sdl2 fclean_sdl2 sdl2

$(SDL2_CONFIGURE):
	tar -xvzf $(SDL2_TAR_GZ)

$(SDL2_BUILD_MAKEFILE): $(LOG_PATH_EXIST)
$(SDL2_BUILD_MAKEFILE): $(SDL2_CONFIGURE) $(SDL2_BUILD_PATH_EXIST)
	cd $(SDL2_BUILD_PATH); ../configure \
	--exec_prefix=$(PROJECT_PATH) \
	--prefix=$(PROJECT_PATH) \
	--datadir=$(PROJECT_PATH)
	+@$(MAKE) --no-print-directory -C $(SDL2_BUILD_PATH) \
	2> $(SDL2_ERROR_LOG)

sdl2:: $(LIBSDL2)
	$(eval override LDFLAGS += $(filter -L% -l%,$(subst $(COMMA),$(SPACE), \
	$(strip $(shell $(SDL2_CONFIG) --libs --static-libs)))))
	$(eval override CFLAGS += $(filter -I%,$(shell $(SDL2_CONFIG) --cflags)))
	$(eval override CPPFLAGS += \
	$(filter-out -I%,$(shell $(SDL2_CONFIG) --cflags)))

$(SDL2_CONFIG): $(LIBSDL2)
$(LIBSDL2): $(SDL2_BUILD_MAKEFILE)
ifeq ($(wildcard $(LIBSDL2)),)
$(LIBSDL2):
	+@$(MAKE) --no-print-directory -C $(SDL2_BUILD_PATH) install \
	2> $(SDL2_ERROR_LOG)
endif

fclean: fclean_sdl2
fclean_sdl2:
ifneq ($(wildcard $(SDL2_CONFIGURE)),)
fclean_sdl2:
	+@$(MAKE) --no-print-directory -C $(SDL2_BUILD_PATH) uninstall
endif

clean: clean_sdl2
clean_sdl2::
	$(RMDIR) $(PROJECT_PATH)/aclocal
ifneq ($(wildcard $(SDL2_CONFIGURE)),)
clean_sdl2::
	+@$(MAKE) --no-print-directory -C $(SDL2_BUILD_PATH) clean
endif
