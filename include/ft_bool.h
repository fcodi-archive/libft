#ifndef FT_BOOL_H
# define FT_BOOL_H

# define ERROR -1
# define FALSE 0
# define TRUE 1

# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>

void			set_bit(uint8_t *word, unsigned bit_index);
void			unset_bit(uint8_t *word, unsigned bit_index);
_Bool 			validate_mask(const char *mask);
_Bool 			set_mask(uint8_t *word, const char *mask);
char			*get_mask(const uint8_t word);
int8_t			byte_shift(void);
uint8_t			byte_start(void);

#endif
