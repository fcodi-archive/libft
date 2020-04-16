#ifndef FT_MEMFUNC_H
# define FT_MEMFUNC_H

# include <stdlib.h>
# include <ft_garbage_collector.h>

void	*memalloc(const size_t size);
void	*memadd(void *ptr);
void	memfree(void *ptr);
void	memfree_all(void);

#endif
