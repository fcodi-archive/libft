# **************************************************************************** #
#	Hashsum
# **************************************************************************** #

ifndef HASHSUM_MK

HASHSUM_MK = $(MK)/hashsum.mk

HASHSUM_BINARY = $(firstword $(shell ls /usr/bin | grep -Ewo "(sha|md5).*sum"))

ifeq ($(HASHSUM_BINARY),)
$(error There is no hashsum calculating binary in your system!)
else
HASHSUM = /usr/bin/$(HASHSUM_BINARY)
endif

endif