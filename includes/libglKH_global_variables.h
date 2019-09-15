#ifndef LIBGLKH_GLOBAL_VARIABLES_H
#define LIBGLKH_GLOBAL_VARIABLES_H
#define KEYS_COUNT 512
#define KEYS_SLEEP_TIME 0.4f

#include <libglKH_global_structs.h>

char*	g_glkeys_states;

double*	g_glkeys_time;

t_key*	g_glkeys;

void (*g_glevent_funcs[TYPE_COUNT])(t_key*, double);

#endif