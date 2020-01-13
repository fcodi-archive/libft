#ifndef FT_BOOL_H
# define FT_BOOL_H

# include <stddef.h>

# define FALSE 0
# define TRUE 1

typedef union 		u_bitfield
{
	uint8_t			uint8;
	unsigned char	word;
	struct
	{
		_Bool		bit0 : 1;
		_Bool 		bit1 : 1;
		_Bool 		bit2 : 1;
		_Bool 		bit3 : 1;
		_Bool 		bit4 : 1;
		_Bool 		bit5 : 1;
		_Bool 		bit6 : 1;
		_Bool 		bit7 : 1;
	};
}					t_bitfield;

typedef union		u_bitfield16
{
	uint16_t		uint16;
	unsigned char	word[sizeof(uint16_t)];
	struct
	{
		_Bool		bit0 : 1;
		_Bool 		bit1 : 1;
		_Bool 		bit2 : 1;
		_Bool 		bit3 : 1;
		_Bool 		bit4 : 1;
		_Bool 		bit5 : 1;
		_Bool 		bit6 : 1;
		_Bool 		bit7 : 1;
		_Bool		bit8 : 1;
		_Bool 		bit9 : 1;
		_Bool 		bit10 : 1;
		_Bool 		bit11 : 1;
		_Bool 		bit12 : 1;
		_Bool 		bit13 : 1;
		_Bool 		bit14 : 1;
		_Bool 		bit15 : 1;
	};
}					t_bitfield16;

typedef union		u_bitfield32
{
	uint32_t		uint32;
	unsigned char	word[sizeof(uint32_t)];
	struct
	{
		_Bool		bit0 : 1;
		_Bool 		bit1 : 1;
		_Bool 		bit2 : 1;
		_Bool 		bit3 : 1;
		_Bool 		bit4 : 1;
		_Bool 		bit5 : 1;
		_Bool 		bit6 : 1;
		_Bool 		bit7 : 1;
		_Bool		bit8 : 1;
		_Bool 		bit9 : 1;
		_Bool 		bit10 : 1;
		_Bool 		bit11 : 1;
		_Bool 		bit12 : 1;
		_Bool 		bit13 : 1;
		_Bool 		bit14 : 1;
		_Bool 		bit15 : 1;
		_Bool		bit16 : 1;
		_Bool 		bit17 : 1;
		_Bool 		bit18 : 1;
		_Bool 		bit19 : 1;
		_Bool 		bit20 : 1;
		_Bool 		bit21 : 1;
		_Bool 		bit22 : 1;
		_Bool 		bit23 : 1;
		_Bool		bit24 : 1;
		_Bool 		bit25 : 1;
		_Bool 		bit26 : 1;
		_Bool 		bit27 : 1;
		_Bool 		bit28 : 1;
		_Bool 		bit29 : 1;
		_Bool 		bit30 : 1;
		_Bool 		bit31 : 1;
	};
}					t_bitfield32;

typedef union		u_bitfield64
{
	uint64_t		uint64;
	unsigned char	word[sizeof(uint64_t)];
	struct
	{
		_Bool		bit0 : 1;
		_Bool		bit1 : 1;
		_Bool		bit2 : 1;
		_Bool		bit3 : 1;
		_Bool		bit4 : 1;
		_Bool		bit5 : 1;
		_Bool		bit6 : 1;
		_Bool		bit7 : 1;
		_Bool		bit8 : 1;
		_Bool		bit9 : 1;
		_Bool		bit10 : 1;
		_Bool		bit11 : 1;
		_Bool		bit12 : 1;
		_Bool		bit13 : 1;
		_Bool		bit14 : 1;
		_Bool		bit15 : 1;
		_Bool		bit16 : 1;
		_Bool		bit17 : 1;
		_Bool		bit18 : 1;
		_Bool		bit19 : 1;
		_Bool		bit20 : 1;
		_Bool		bit21 : 1;
		_Bool		bit22 : 1;
		_Bool		bit23 : 1;
		_Bool		bit24 : 1;
		_Bool		bit25 : 1;
		_Bool		bit26 : 1;
		_Bool		bit27 : 1;
		_Bool		bit28 : 1;
		_Bool		bit29 : 1;
		_Bool		bit30 : 1;
		_Bool		bit31 : 1;
		_Bool		bit32 : 1;
		_Bool		bit33 : 1;
		_Bool		bit34 : 1;
		_Bool		bit35 : 1;
		_Bool		bit36 : 1;
		_Bool		bit37 : 1;
		_Bool		bit38 : 1;
		_Bool		bit39 : 1;
		_Bool		bit40 : 1;
		_Bool		bit41 : 1;
		_Bool		bit42 : 1;
		_Bool		bit43 : 1;
		_Bool		bit44 : 1;
		_Bool		bit45 : 1;
		_Bool		bit46 : 1;
		_Bool		bit47 : 1;
		_Bool		bit48 : 1;
		_Bool		bit49 : 1;
		_Bool		bit50 : 1;
		_Bool		bit51 : 1;
		_Bool		bit52 : 1;
		_Bool		bit53 : 1;
		_Bool		bit54 : 1;
		_Bool		bit55 : 1;
		_Bool		bit56 : 1;
		_Bool		bit57 : 1;
		_Bool		bit58 : 1;
		_Bool		bit59 : 1;
		_Bool		bit60 : 1;
		_Bool		bit61 : 1;
		_Bool		bit62 : 1;
		_Bool		bit63 : 1;
	};
}					t_bitfield64;

typedef union		u_bitfield128
{
	__int128		int128;
	unsigned char	word[sizeof(__int128)];
	struct
	{
		_Bool		bit0 : 1;
		_Bool		bit1 : 1;
		_Bool		bit2 : 1;
		_Bool		bit3 : 1;
		_Bool		bit4 : 1;
		_Bool		bit5 : 1;
		_Bool		bit6 : 1;
		_Bool		bit7 : 1;
		_Bool		bit8 : 1;
		_Bool		bit9 : 1;
		_Bool		bit10 : 1;
		_Bool		bit11 : 1;
		_Bool		bit12 : 1;
		_Bool		bit13 : 1;
		_Bool		bit14 : 1;
		_Bool		bit15 : 1;
		_Bool		bit16 : 1;
		_Bool		bit17 : 1;
		_Bool		bit18 : 1;
		_Bool		bit19 : 1;
		_Bool		bit20 : 1;
		_Bool		bit21 : 1;
		_Bool		bit22 : 1;
		_Bool		bit23 : 1;
		_Bool		bit24 : 1;
		_Bool		bit25 : 1;
		_Bool		bit26 : 1;
		_Bool		bit27 : 1;
		_Bool		bit28 : 1;
		_Bool		bit29 : 1;
		_Bool		bit30 : 1;
		_Bool		bit31 : 1;
		_Bool		bit32 : 1;
		_Bool		bit33 : 1;
		_Bool		bit34 : 1;
		_Bool		bit35 : 1;
		_Bool		bit36 : 1;
		_Bool		bit37 : 1;
		_Bool		bit38 : 1;
		_Bool		bit39 : 1;
		_Bool		bit40 : 1;
		_Bool		bit41 : 1;
		_Bool		bit42 : 1;
		_Bool		bit43 : 1;
		_Bool		bit44 : 1;
		_Bool		bit45 : 1;
		_Bool		bit46 : 1;
		_Bool		bit47 : 1;
		_Bool		bit48 : 1;
		_Bool		bit49 : 1;
		_Bool		bit50 : 1;
		_Bool		bit51 : 1;
		_Bool		bit52 : 1;
		_Bool		bit53 : 1;
		_Bool		bit54 : 1;
		_Bool		bit55 : 1;
		_Bool		bit56 : 1;
		_Bool		bit57 : 1;
		_Bool		bit58 : 1;
		_Bool		bit59 : 1;
		_Bool		bit60 : 1;
		_Bool		bit61 : 1;
		_Bool		bit62 : 1;
		_Bool		bit63 : 1;
		_Bool		bit64 : 1;
		_Bool		bit65 : 1;
		_Bool		bit66 : 1;
		_Bool		bit67 : 1;
		_Bool		bit68 : 1;
		_Bool		bit69 : 1;
		_Bool		bit70 : 1;
		_Bool		bit71 : 1;
		_Bool		bit72 : 1;
		_Bool		bit73 : 1;
		_Bool		bit74 : 1;
		_Bool		bit75 : 1;
		_Bool		bit76 : 1;
		_Bool		bit77 : 1;
		_Bool		bit78 : 1;
		_Bool		bit79 : 1;
		_Bool		bit80 : 1;
		_Bool		bit81 : 1;
		_Bool		bit82 : 1;
		_Bool		bit83 : 1;
		_Bool		bit84 : 1;
		_Bool		bit85 : 1;
		_Bool		bit86 : 1;
		_Bool		bit87 : 1;
		_Bool		bit88 : 1;
		_Bool		bit89 : 1;
		_Bool		bit90 : 1;
		_Bool		bit91 : 1;
		_Bool		bit92 : 1;
		_Bool		bit93 : 1;
		_Bool		bit94 : 1;
		_Bool		bit95 : 1;
		_Bool		bit96 : 1;
		_Bool		bit97 : 1;
		_Bool		bit98 : 1;
		_Bool		bit99 : 1;
		_Bool		bit100 : 1;
		_Bool		bit101 : 1;
		_Bool		bit102 : 1;
		_Bool		bit103 : 1;
		_Bool		bit104 : 1;
		_Bool		bit105 : 1;
		_Bool		bit106 : 1;
		_Bool		bit107 : 1;
		_Bool		bit108 : 1;
		_Bool		bit109 : 1;
		_Bool		bit110 : 1;
		_Bool		bit111 : 1;
		_Bool		bit112 : 1;
		_Bool		bit113 : 1;
		_Bool		bit114 : 1;
		_Bool		bit115 : 1;
		_Bool		bit116 : 1;
		_Bool		bit117 : 1;
		_Bool		bit118 : 1;
		_Bool		bit119 : 1;
		_Bool		bit120 : 1;
		_Bool		bit121 : 1;
		_Bool		bit122 : 1;
		_Bool		bit123 : 1;
		_Bool		bit124 : 1;
		_Bool		bit125 : 1;
		_Bool		bit126 : 1;
		_Bool		bit127 : 1;
	};
}					t_bitfield128;

typedef union		u_type_punning
{
	t_bitfield		bitfield[sizeof(__int128)];
	unsigned char	word[sizeof(__int128)];
	__int128		int128;
	uint64_t		uint64;
	uint32_t 		uint32;
	uint16_t 		uint16;
	uint8_t			uint8;
	ptrdiff_t		ptrdiff;
	wchar_t 		wchar;
	size_t			size;
	float 			f_float;
	double			f_double;
	long double		f_long_double;
}					t_type_punning;

#endif
