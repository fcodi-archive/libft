#ifndef FT_STDINT_H
# define FT_STDINT_H

# ifdef __INT8_TYPE__
typedef __INT8_TYPE__ int8_t;
# endif
# ifdef __INT16_TYPE__
typedef __INT16_TYPE__ int16_t;
# endif
# ifdef __INT32_TYPE__
typedef __INT32_TYPE__ int32_t;
# endif
# ifdef __INT64_TYPE__
typedef __INT64_TYPE__ int64_t;
# endif
# ifdef __UINT8_TYPE__
typedef __UINT8_TYPE__ uint8_t;
# endif
# ifdef __UINT16_TYPE__
typedef __UINT16_TYPE__ uint16_t;
# endif
# ifdef __UINT32_TYPE__
typedef __UINT32_TYPE__ uint32_t;
# endif
# ifdef __UINT64_TYPE__
typedef __UINT64_TYPE__ uint64_t;
# endif

# ifdef __INTPTR_TYPE__
typedef __INTPTR_TYPE__ intptr_t;
# endif
# ifdef __UINTPTR_TYPE__
typedef __UINTPTR_TYPE__ uintptr_t;
# endif

# ifdef __INTMAX_TYPE__
typedef __INTMAX_TYPE__ intmax_t;
# endif
# ifdef __UINTMAX_TYPE__
typedef __UINTMAX_TYPE__ uintmax_t;
# endif

/* 7.18.2 Limits of specified-width integer types */

# ifdef __INT8_MAX__
#  undef INT8_MAX
#  define INT8_MAX __INT8_MAX__
#  undef INT8_MIN
#  define INT8_MIN (-INT8_MAX - 1)
# endif
# ifdef __UINT8_MAX__
#  undef UINT8_MAX
#  define UINT8_MAX __UINT8_MAX__
# endif
# ifdef __INT16_MAX__
#  undef INT16_MAX
#  define INT16_MAX __INT16_MAX__
#  undef INT16_MIN
#  define INT16_MIN (-INT16_MAX - 1)
# endif
#  ifdef __UINT16_MAX__
#  undef UINT16_MAX
#  define UINT16_MAX __UINT16_MAX__
# endif
# ifdef __INT32_MAX__
#  undef INT32_MAX
#  define INT32_MAX __INT32_MAX__
#  undef INT32_MIN
#  define INT32_MIN (-INT32_MAX - 1)
# endif
#  ifdef __UINT32_MAX__
#  undef UINT32_MAX
#  define UINT32_MAX __UINT32_MAX__
# endif
#  ifdef __INT64_MAX__
#  undef INT64_MAX
#  define INT64_MAX __INT64_MAX__
#  undef INT64_MIN
#  define INT64_MIN (-INT64_MAX - 1)
# endif
# ifdef __UINT64_MAX__
#  undef UINT64_MAX
#  define UINT64_MAX __UINT64_MAX__
# endif

# ifdef __INTPTR_MAX__
#  undef INTPTR_MAX
#  define INTPTR_MAX __INTPTR_MAX__
#  undef INTPTR_MIN
#  define INTPTR_MIN (-INTPTR_MAX - 1)
# endif
#  ifdef __UINTPTR_MAX__
#  undef UINTPTR_MAX
#  define UINTPTR_MAX __UINTPTR_MAX__
# endif

# undef INTMAX_MAX
# define INTMAX_MAX __INTMAX_MAX__
# undef INTMAX_MIN
# define INTMAX_MIN (-INTMAX_MAX - 1)
# undef UINTMAX_MAX
# define UINTMAX_MAX __UINTMAX_MAX__

# undef PTRDIFF_MAX
# define PTRDIFF_MAX __PTRDIFF_MAX__
# undef PTRDIFF_MIN
# define PTRDIFF_MIN (-PTRDIFF_MAX - 1)

# undef SIZE_MAX
# define SIZE_MAX __SIZE_MAX__

# undef WCHAR_MAX
# define WCHAR_MAX __WCHAR_MAX__
# undef WCHAR_MIN
# define WCHAR_MIN __WCHAR_MIN__

# undef WINT_MAX
# define WINT_MAX __WINT_MAX__
# undef WINT_MIN
# define WINT_MIN __WINT_MIN__

#endif
