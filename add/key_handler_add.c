#include <lgkh.h>
#include <libglKH_global_variables.h>
#include <libglKH_global_structs.h>
#include <stdio.h>
#include <stdlib.h>

static void add_key_list(t_key *const restrict elem)
{
	t_key* lst;

	lst = g_glkeys;
	while (lst && lst->next && lst->click_type != elem->click_type)
		lst = lst->next;
	if (lst && !lst->next)
	{
		lst->next = elem;
		return;
	}
	while (lst && lst->click_type == elem->click_type
		&& lst->next && lst->next->click_type == elem->click_type)
		lst = lst->next;
	if (lst == g_glkeys)
	{
		elem->next = g_glkeys;
		g_glkeys = elem;
		return;
	}
	elem->next = lst->next;
	lst->next = elem;
}

char	key_handler_add(const size_t key, const t_click_type click_type, void *const args,
		char (*const condition)(void), void (*const reaction)(void*))
{
	t_key *const restrict elem = (t_key*)malloc(sizeof(t_key));

	if (!elem)
		return (0);
	elem->args = args;
	elem->key = key;
	elem->click_type = click_type;
	elem->condition = condition;
	elem->reaction = reaction;
	elem->press_state = 0;
	elem->next = 0;
	add_key_list(elem);
	return (1);
}