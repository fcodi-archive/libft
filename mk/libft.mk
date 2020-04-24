# -----------------------------------------------------------------------------
#	Libft
# -----------------------------------------------------------------------------

LIBFT = libft.a

LIBFT_DIRECTORY = libft

LIBFT_PATH = $(PROJECT_PATH)/$(LIBFT_DIRECTORY)

LIBFT_MODULE_DIRECTORY = module

LIBFT_MODULE_PATH = $(LIBFT_PATH)/$(LIBFT_MODULE_DIRECTORY)

# -----------------------------------------------------------------------------
#	MK
# -----------------------------------------------------------------------------

LIBFT_MK_DIRECTORY = mk

LIBFT_MK_PATH = $(LIBFT_PATH)/$(LIBFT_MK_DIRECTORY)

BREW_MK = $(LIBFT_MK_PATH)/brew.mk

FLAGS_MK = $(LIBFT_MK_PATH)/flags.mk

MAKEFILE_MK = $(LIBFT_MK_PATH)/makefile.mk

OS_MK = $(LIBFT_MK_PATH)/os.mk

VAR_MK = $(LIBFT_MK_PATH)/var.mk

MODULE_MK = $(LIBFT_MK_PATH)/module.mk