cmake_minimum_required(VERSION 3.14)
project(libft)

include_directories(. include ft_bool/include ft_astr/include
		ft_convert/include ft_list/include ft_memfunc/include ft_size/include
		ft_stddef/include ft_stdio/include ft_string/include)

add_library(ft STATIC
		ft_convert/src/ft_atoi.c
		ft_convert/src/ft_toupper.c
		ft_convert/src/ft_tolower.c
		ft_convert/src/ft_itoa.c
		ft_list/src/ft_lstnew.c
		ft_list/src/ft_lstadd.c
		ft_list/src/ft_lstiter.c
		ft_list/src/ft_lstdel.c
		ft_list/src/ft_lstdelone.c
		ft_list/src/ft_lstmap.c
		ft_astr/src/ft_astrdel.c
		ft_string/src/ft_strstr.c
		ft_string/src/ft_strtrim.c
		ft_string/src/ft_strlen.c
		ft_memfunc/src/ft_bzero.c
		ft_string/src/ft_strncat.c
		ft_string/src/ft_strcat.c
		ft_bool/src/ft_isalnum.c
		ft_string/src/ft_strnew.c
		ft_stdio/src/ft_putchar.c
		ft_string/src/ft_strsub.c
		ft_string/src/ft_strrchr.c
		ft_string/src/ft_strchr.c
		ft_memfunc/src/ft_memalloc.c
		ft_stdio/src/ft_putnbr_fd.c
		ft_bool/src/ft_isprint.c
		ft_bool/src/ft_islower.c
		ft_stdio/src/ft_putstr_fd.c
		ft_string/src/ft_strmap.c
		ft_string/src/ft_strequ.c
		ft_memfunc/src/ft_memcmp.c
		ft_string/src/ft_strlenc.c
		ft_stdio/src/ft_putchar_fd.c
		ft_string/src/ft_strnstr.c
		ft_string/src/ft_strlcat.c
		ft_memfunc/src/ft_memmove.c
		ft_stdio/src/ft_putstr.c
		src/ft_uintlen.c
		ft_string/src/ft_strcpy.c
		ft_stdio/src/ft_putendl.c
		ft_string/src/ft_strncpy.c
		ft_bool/src/ft_isupper.c
		ft_string/src/ft_strncmp.c
		ft_memfunc/src/ft_memdel.c
		ft_string/src/ft_strdup.c
		ft_string/src/ft_strclr.c
		ft_memfunc/src/ft_memset.c
		ft_string/src/ft_strnequ.c
		ft_string/src/ft_strnlen.c
		ft_string/src/ft_striteri.c
		ft_memfunc/src/ft_memcpy.c
		ft_string/src/ft_strjoin.c
		ft_bool/src/ft_isspace.c
		ft_bool/src/ft_isdigit.c
		ft_string/src/ft_strsplit.c
		ft_string/src/ft_striter.c
		ft_bool/src/ft_isascii.c
		ft_stdio/src/ft_putendl_fd.c
		ft_memfunc/src/ft_memccpy.c
		ft_string/src/ft_strdel.c
		ft_string/src/ft_strcmp.c
		ft_memfunc/src/ft_memchr.c
		ft_string/src/ft_strmapi.c
		ft_stdio/src/ft_putnbr.c
		ft_bool/src/ft_isalpha.c)