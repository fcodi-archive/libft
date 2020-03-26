#ifndef FT_ATOX_H
# define FT_ATOX_H
# define VALID_FLOAT_CHARS_EX "1234567890.-+"
# define VALID_FLOAT_CHARS "1234567890.-+Ee"
# include <libft.h>
# include <ft_bool.h>
# include <math.h>

typedef __int128 			int128_t;
typedef unsigned __int128	uint128_t;

unsigned long long	ft_atollu_base(const char *string,
		const unsigned short base);
long long			ft_atoll_base(const char *string,
		const unsigned short base);
unsigned long		ft_atolu_base(const char *string,
		const unsigned short base);
long				ft_atol_base(const char *string,
		const unsigned short base);
unsigned			ft_atou_base(const char *string,
		const unsigned short base);
int					ft_atoi_base(const char *string,
		const unsigned short base);
_Bool				ft_atox_validate_number(const char *number,
		const unsigned short base);
_Bool				ft_is_base_digit(const char n,
		const unsigned short base);
int					ft_get_base_digit(const char n);

int128_t	int_after_dot(const char *number);
size_t	digits_after_dot(const char *number);
_Bool	is_valid_float_string_ex(const char *number);
size_t	digits_before_dot(const char *number);
int128_t	int_before_dot(const char *number);
long double	ft_atold_ex(const char *number);
double		ft_atod_ex(const char *number);
float		ft_atof_ex(const char *number);

#endif
