#include <ft_memfunc.h>

static const char		*get_return_code_message(const t_return_code code)
{
	if (code == rc_ok)
		return (RC_OK);
	if (code == rc_error)
		return (RC_ERROR);
	if (code == rc_allocation_fail)
		return (RC_ALLOCATION_FAIL);
	if (code == rc_garbage_collector)
		return (RC_GARBAGE_COLLECTOR);
	if (code == rc_initialize_fail)
		return (RC_SDL_INITIALIZE_FAIL);
	return (NULL);
}

void	ft_exit(const int code, const char *message)
{
	const char		*rc_message = get_return_code_message(code);

	if (code)
	{
		if (rc_message)
			ft_putendl(rc_message);
		ft_putendl(message);
	}
	ft_free((void *)ft_free);
	exit(code);
}