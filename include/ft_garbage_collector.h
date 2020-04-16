#ifndef FT_GARBAGE_COLLECTOR_H
# define FT_GARBAGE_COLLECTOR_H

# include <ft_memfunc.h>
# include <ft_tpointer_keeper.h>

typedef t_pointer_keeper t_garbage_collector;

t_garbage_collector		*get_garbage_collector(void);

#endif