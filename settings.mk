# **************************************************************************** #
#	Settings
# **************************************************************************** #

PREFIX ?= $(CURDIR)

#TODO Провести больше тестов
#BREW_DEPENDENCY = wget chromedriver неСуществующаяЗависимость

#TODO Фильтр правил НЕ РАБОТАЕТ - почему?
FILTER_RULES = all debug _cflags _ldflags _ipath _lpath _cppflags

ifeq ($(notdir $(CURDIR)),libft)
MK ?= $(PREFIX)/mk
endif

#TODO Рассмотреть возможность переноса стандартных настроек в другой файл

OBJECT_DIRECTORY = .obj

OBJECT_PATH ?= $(PREFIX)/$(OBJECT_DIRECTORY)

# **************************************************************************** #
#	Libft sources
# **************************************************************************** #

NAME := $(PREFIX)/libft.a

SOURCE_FILES ?= convert_string_array.c \
	ft_strncmp.c \
	ft_strcmp.c \
	ft_itoa.c \
	ft_pointer_keeper_converter.c \
	ft_csub.c \
	ft_strsplit.c \
	ft_astr_len.c \
	get_word_end_pointer.c \
	ft_atol_base.c \
	get_next_line.c \
	ft_strncat.c \
	memalloc.c \
	ft_memcpy.c \
	ft_astr_tolower.c \
	get_word_start_pointer.c \
	ft_pointer_keeper_get.c \
	ft_strcpy.c \
	ft_astr_del.c \
	ft_atof_ex.c \
	ft_pointer_keeper_attr.c \
	new_string.c \
	ft_lstiter.c \
	ft_bit_endian.c \
	ft_strtrim.c \
	ft_lstdelone.c \
	ft_isupper.c \
	ft_putstr.c \
	ft_putchar_fd.c \
	memfree.c \
	get_garbage_collector.c \
	ft_memset.c \
	ft_strndup.c \
	ft_atod_ex.c \
	ft_toupper.c \
	ft_isdigit.c \
	ft_putnbr_fd.c \
	ft_uintlen.c \
	ft_putnbr.c \
	ft_strlcat.c \
	memadd.c \
	ft_isalnum.c \
	ft_putendl.c \
	cut_string.c \
	ft_write_free.c \
	ft_realloc.c \
	ft_striter.c \
	ft_astr_astr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_strncpy.c \
	get_word_end_position.c \
	ft_strnequ.c \
	ft_astr_fill_c.c \
	ft_putchar.c \
	ft_cadd.c \
	ft_cabsl.c \
	ft_islower.c \
	ft_atoi.c \
	ft_memchr.c \
	parse_float_ex.c \
	ft_cmul.c \
	ft_strjoin.c \
	ft_cpowl.c \
	parse_integer.c \
	ft_astr_new.c \
	ft_bit_edit.c \
	ft_isprint.c \
	get_word_start_position.c \
	ft_strmapi.c \
	ft_ishex.c \
	ft_strnew.c \
	ft_atox_utils.c \
	ft_strdup.c \
	ft_memdel.c \
	ft_strsub.c \
	ft_atold_ex.c \
	ft_lstdel.c \
	ft_memccpy.c \
	ft_strstr.c \
	ft_strput.c \
	ft_strequ.c \
	ft_tolower.c \
	ft_malloc.c \
	ft_strlen.c \
	memfree_all.c \
	ft_lstnew.c \
	string_array_size.c \
	ft_strmap.c \
	join_strings.c \
	ft_calloc.c \
	ft_bzero.c \
	ft_atou_base.c \
	ft_strnlen.c \
	ft_atollu_base.c \
	ft_exit.c \
	ft_strcat.c \
	ft_atoi_base.c \
	ft_pointer_destroy.c \
	ft_strclr.c \
	ft_putendl_fd.c \
	ft_strrchr.c \
	ft_lstmap.c \
	destroy_string_array.c \
	ft_striteri.c \
	ft_memmove.c \
	ft_pointer.c \
	ft_atoll_base.c \
	ft_isspace.c \
	ft_strnchri.c \
	ft_putstr_fd.c \
	ft_strlenc.c \
	ft_atolu_base.c \
	ft_memalloc.c \
	ft_strchr.c \
	ft_lstadd.c \
	ft_astr_put.c \
	ft_pointer_keeper.c \
	ft_isascii.c \
	ft_strdel.c \
	ft_nsym.c \
	ft_bit_mask.c \
	ft_isalpha.c \
	ft_cdiv.c

INCLUDE_FILES ?= ft_atox.h \
	get_next_line.h \
	ft_complex.h \
	libft.h \
	ft_string.h \
	ft_bool.h \
	ft_pointer_keeper_structs.h \
	ft_string_array.h \
	ft_pointer_keeper.h \
	ft_memfunc.h