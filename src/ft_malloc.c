#include <ft_memfunc.h>

void	*ft_malloc(const size_t size)
{
	static t_garbage_collector	*collector = NULL;
	void						*ptr;

	if (!size || !(ptr = malloc(size)))
		return (NULL);
	ft_bzero(ptr, size);
	if (!collector && !(collector = get_garbage_collector())
		|| !collector->add(collector, ptr))
	{
		free(ptr);
		ft_exit(rc_garbage_collector, EXIT_MESSAGE);
	}
	return (ptr);
}