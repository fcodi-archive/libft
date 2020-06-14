# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcodi <fcodi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 17:56:52 by fcodi             #+#    #+#              #
#    Updated: 2020/06/14 17:07:48 by fcodi            ###   ########.fr        #
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
	$(RM)r $(OBJECT_PATH) var

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

$(OBJECT_FILES): $(VARIABLE_FILES)

$(NAME): $(OBJECT_FILES) $(INCLUDE_FILES)
$(NAME): $(NAME)($(OBJECT_FILES) $(INCLUDE_FILES))

endif