# **************************************************************************** #
#	General
# **************************************************************************** #

NAME ?= libft.a

SOURCE_FILES ?= convert_string_array.c \
	get_word_end_position.c \
	ft_strcpy.c \
	ft_lstnew.c \
	ft_memmove.c \
	ft_wchar_to_string.c \
	ft_strlen.c \
	ft_strjoin.c \
	get_word_start_position.c \
	ft_malloc.c \
	memfree_all.c \
	new_string.c \
	ft_ishex.c \
	memfree.c \
	ft_strequ.c \
	ft_cabsl.c \
	parse_integer.c \
	ft_memcmp.c \
	tview.c \
	ft_putchar_fd.c \
	ft_calloc.c \
	ft_cpowl.c \
	string_array_size.c \
	ft_tpointer.c \
	ft_itoa.c \
	ft_isalnum.c \
	ft_strndup.c \
	ft_strnequ.c \
	ft_cmul.c \
	ft_striteri.c \
	ft_atoll_base.c \
	ft_tpointer_keeper_converter.c \
	ft_strnew.c \
	ft_strmapi.c \
	join_strings.c \
	ft_isprint.c \
	ft_bit_mask.c \
	ft_strlenc.c \
	ft_strmap.c \
	ft_isdigit.c \
	ft_strchr.c \
	ft_islower.c \
	ft_atof_ex.c \
	cut_string.c \
	ft_lstdelone.c \
	ft_astr_fill_c.c \
	ft_tpointer_keeper.c \
	ft_strdup.c \
	ft_atoi_base.c \
	ft_strlcat.c \
	ft_lstadd.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_astr_len.c \
	ft_memset.c \
	ft_putnbr_fd.c \
	parse_float_ex.c \
	ft_strnlen.c \
	ft_uintlen.c \
	get_word_start_pointer.c \
	ft_strput.c \
	ft_memalloc.c \
	destroy_string_array.c \
	get_garbage_collector.c \
	ft_tpointer_destroy.c \
	ft_astr_new.c \
	ft_tpointer_keeper_get.c \
	ft_strtrim.c \
	ft_strclr.c \
	ft_astr_tolower.c \
	ft_strnchri.c \
	ft_strcat.c \
	ft_isalpha.c \
	ft_striter.c \
	ft_bzero.c \
	ft_astr_put.c \
	ft_lstiter.c \
	ft_strsplit.c \
	ft_astr_del.c \
	ft_strstr.c \
	ft_memcpy.c \
	ft_putstr.c \
	ft_atod_ex.c \
	ft_bit_edit.c \
	ft_strdel.c \
	ft_strsub.c \
	ft_atou_base.c \
	ft_memccpy.c \
	ft_atox_utils.c \
	ft_isspace.c \
	memalloc.c \
	ft_atol_base.c \
	get_next_line.c \
	ft_realloc.c \
	memadd.c \
	tview_init.c \
	ft_lstmap.c \
	ft_cdiv.c \
	ft_exit.c \
	ft_astr_astr.c \
	ft_cadd.c \
	ft_atolu_base.c \
	ft_memdel.c \
	ft_tpointer_keeper_attr.c \
	ft_putnbr.c \
	ft_putchar.c \
	ft_write_free.c \
	ft_putendl.c \
	get_word_end_pointer.c \
	ft_strncpy.c \
	ft_memchr.c \
	ft_putendl_fd.c \
	ft_lstdel.c \
	ft_tolower.c \
	ft_nsym.c \
	ft_atoi.c \
	ft_csub.c \
	ft_strncat.c \
	ft_atollu_base.c \
	ft_bit_endian.c \
	ft_strcmp.c \
	ft_atold_ex.c \
	ft_putstr_fd.c \
	twin.c \
	ft_isascii.c \
	ft_isupper.c \
	ft_toupper.c

LIBFT_INCLUDE_FILES ?= ft_atox.h \
	ft_string.h \
	ft_garbage_collector.h \
	ft_mlx.h \
	type_punning.h \
	ft_string_array.h \
	libft.h \
	ft_complex.h \
	ft_mlx_events.h \
	ft_bool.h \
	ft_unicode.h \
	ft_tpointer_keeper.h \
	ft_memfunc.h \
	get_next_line.h

INCLUDE_FILES ?= $(LIBFT_INCLUDE_FILES)

# **************************************************************************** #
#	Makefile definitions
# **************************************************************************** #

PROJECT_PATH ?= $(CURDIR)

LIBFT_DIRECTORY ?= libft

ifeq ($(notdir $(CURDIR)),$(LIBFT_DIRECTORY))
LIBFT_PATH ?= $(CURDIR)
else
LIBFT_PATH ?= $(PROJECT_PATH)/$(LIBFT_DIRECTORY)
endif

-include $(LIBFT_PATH)/mk/libft.mk

# **************************************************************************** #
#	Rules
# **************************************************************************** #

all: $(NAME)

ifeq ($(CURDIR),$(OBJECT_PATH))
$(NAME): $(INCLUDE_FILES) $(OBJECT_FILES)
ifeq ($(suffix $(NAME)),.a)
$(NAME): $(NAME)($(INCLUDE_FILES) $(OBJECT_FILES))
else
$(NAME): $(INCLUDE_FILES) $(OBJECT_FILES)
	$(CC) $^ $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
endif
else
export
$(NAME): $(OBJECT_PATH_EXIST)
	@$(MAKE) --directory="$(OBJECT_PATH)" --makefile="$(LIBFT_MAKEFILE)" \
	NAME="$(PROJECT_PATH)/$(NAME)" PROJECT_PATH="$(PROJECT_PATH)" \
	CFLAGS="$(sort $(CFLAGS))" LDFLAGS="$(sort $(LDFLAGS))" \
	CPPFLAGS="$(sort $(CPPFLAGS))" LIBRARY_PATH="$(sort $(_LIBRARY_PATH))" \
	SOURCE_PATH="$(sort $(_SOURCE_PATH))" OBJECT_PATH="$(OBJECT_PATH)" \
	INCLUDE_PATH="$(sort $(_INCLUDE_PATH))" \
	INCLUDE_FILES="$(sort $(_INCLUDE_FILES))"
endif

clean:
	$(RMDIR) $(OBJECT_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all