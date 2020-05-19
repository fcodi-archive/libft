# **************************************************************************** #
#	SDL2 Variables
# **************************************************************************** #

RMDIR ?= $(RM)r

SDL2_TAR_GZ = $(PREFIX)/SDL2-2.0.12.tar.gz

SDL2_DIRECTORY = SDL2-2.0.12

SDL2_PATH = $(PREFIX)/$(SDL2_DIRECTORY)

SDL2_BUILD_PATH = $(SDL2_PATH)/build

SDL2_CONFIGURE = $(SDL2_PATH)/configure

SDL2_BUILD_MAKEFILE = $(SDL2_BUILD_PATH)/Makefile

BINARY_PATH = $(PREFIX)/bin

SDL2_CONFIG = $(BINARY_PATH)/sdl2-config

LIBSDL2 = $(PREFIX)/lib/libSDL2.a

# **************************************************************************** #
#	SDL2 Rules
# **************************************************************************** #

.PHONY: all re clean fclean

all: $(SDL2_CONFIG)

$(SDL2_CONFIG): $(LIBSDL2)
$(LIBSDL2):: $(SDL2_BUILD_MAKEFILE)
ifeq ($(wildcard $(LIBSDL2)),)
$(LIBSDL2)::
	+@$(MAKE) --no-print-directory -C $(SDL2_BUILD_PATH) install \
	2>/dev/null
endif

$(SDL2_BUILD_MAKEFILE): $(SDL2_CONFIGURE)
	-mkdir -p $(@D)
	cd $(SDL2_BUILD_PATH); ../configure \
	--exec_prefix=$(CURDIR) \
	--prefix=$(CURDIR) \
	--datadir=$(CURDIR) 2>/dev/null
	+@$(MAKE) --no-print-directory -C $(SDL2_BUILD_PATH) 2>/dev/null

$(SDL2_CONFIGURE):
	tar -xvzf $(SDL2_TAR_GZ)

fclean:
ifneq ($(wildcard $(SDL2_CONFIGURE)),)
fclean:
	+@$(MAKE) --no-print-directory -C $(SDL2_BUILD_PATH) uninstall
endif

clean::
	$(RMDIR) $(CURDIR)/aclocal $(CURDIR)/bin $(CURDIR)/lib
ifneq ($(wildcard $(SDL2_CONFIGURE)),)
clean::
	+@$(MAKE) --no-print-directory -C $(SDL2_BUILD_PATH) clean
endif

re: fclean all