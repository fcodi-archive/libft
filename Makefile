# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:56:52 by fcodi             #+#    #+#              #
#    Updated: 2020/05/01 10:42:41 by fcodi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	Pre-build
# **************************************************************************** #

-include settings.mk

ifneq ($(notdir $(CURDIR)),$(OBJECT_DIRECTORY))

.SUFFIXES:

include $(MK)/make_target.mk

$(eval $(call _MAKE_TARGET,MAKE_TARGET,\
	$(OBJECT_DIRECTORY),$(PREFIX)/Makefile,$(PREFIX)))

.PHONY: all clean fclean re $(NAME)

all: $(NAME)

$(NAME):
	-@mkdir -p $(OBJECT_PATH)
	+@$(MAKE_TARGET)

Makefile : ; @
%.mk :: ; @

% :: all ; @

clean:
	$(RM)r $(OBJECT_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

else

# **************************************************************************** #
#	Build
# **************************************************************************** #

include ../settings.mk
include $(MK)/prefix.mk

all: $(NAME)

ifeq ($(suffix $(NAME)),.a)
$(NAME): $(NAME)($(OBJECT_FILES) $(INCLUDE_FILES))
else
$(NAME): $(OBJECT_FILES) $(INCLUDE_FILES)
	$(CC) $(filter %.o,$^) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
endif

endif