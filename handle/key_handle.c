#include <libglKH_global_structs.h>
#include <libglKH_global_variables.h>
#include "handle.h"

static void		release(t_key *const restrict elem)
{
	if (!g_glkeys_states[elem->key])
	{
		if (elem->click_type == KEY_RELEASE && elem->press_state)
			elem->reaction(elem->args);
		elem->press_state = 0;
	}
}

static t_key*	cycle(void (*const ev)(t_key*, double), t_key *restrict elem,
		const double time, const t_click_type type)
{
	while (elem && elem->click_type == type)
	{
		ev(elem, time);
		release(elem);
		elem = elem->next;
	}
	return (elem);
}

void	key_handle(const double time)
{
	t_key*	elem;

	elem = g_glkeys;
	if (elem)
		elem = cycle(g_glevent_funcs[elem->click_type - 1], elem, time, elem->click_type);
	if (elem)
		elem = cycle(g_glevent_funcs[elem->click_type - 1], elem, time, elem->click_type);
	if (elem)
		elem = cycle(g_glevent_funcs[elem->click_type - 1], elem, time, elem->click_type);
	if (elem)
		cycle(g_glevent_funcs[elem->click_type - 1], elem, time, elem->click_type);
}
