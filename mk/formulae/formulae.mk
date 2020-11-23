include $(MK)/brew.mk

ifndef $1_MK
$1_MK = $(FORMULAE)/$1.mk

$1 = $2

ifeq ($(wildcard $2),)
$2: $(BREW)
	$(BREW) install $1
endif

endif