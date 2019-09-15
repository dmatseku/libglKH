#ifndef HANDLE_H
#define HANDLE_H

#include <libglKH_global_structs.h>

void	event_press(t_key* elem, double time);

void	event_mono_repeat(t_key* elem, double time);

void	event_repeat(t_key* elem, double time);

void	event_release(t_key* elem, double time);

#endif