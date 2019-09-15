#include <libglKH_global_structs.h>
#include <libglKH_global_variables.h>

void	event_press(t_key *const restrict elem, const double time)
{
	(void)time;
	if (g_glkeys_states[elem->key] && !elem->press_state && (!elem->condition || elem->condition()))
	{
		elem->reaction(elem->args);
		elem->press_state = 2;
	}
}

void	event_mono_repeat(t_key *const restrict elem, const double time)
{
	(void)time;
	if (g_glkeys_states[elem->key] && (!elem->condition || elem->condition()))
		elem->reaction(elem->args);
}

void	event_repeat(t_key *const restrict elem, const double time)
{
	if (g_glkeys_states[elem->key] && (!elem->condition || elem->condition()))
	{
		if (!elem->press_state)
		{
			elem->reaction(elem->args);
			elem->press_state = 1;
			g_glkeys_time[elem->key] = time;
		}
		else if (time - g_glkeys_time[elem->key] > KEYS_SLEEP_TIME)
			elem->reaction(elem->args);
	}
}

void	event_release(t_key *const restrict elem, const double time)
{
	(void)time;
	if (g_glkeys_states[elem->key] && (!elem->condition || elem->condition()))
		elem->press_state = 2;
}