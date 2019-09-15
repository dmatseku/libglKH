#include <string.h>
#include <libglKH_global_variables.h>
#include <stdlib.h>
#include <lgkh.h>
#include "../handle/handle.h"

char	key_handler_init(GLFWwindow *const restrict window)
{
	glfwSetKeyCallback(window, my_key_callback);
	if (!(g_glkeys_states = (char*)malloc(sizeof(char) * KEYS_COUNT)))
		return (0);
	if (!(g_glkeys_time = (double*)malloc(sizeof(double) * KEYS_COUNT)))
		return (0);
	memset(g_glkeys_states, 0, sizeof(char) * KEYS_COUNT);
	memset(g_glkeys_time, 0, sizeof(double) * KEYS_COUNT);
	g_glkeys = 0;
	g_glevent_funcs[0] = event_press;
	g_glevent_funcs[1] = event_repeat;
	g_glevent_funcs[2] = event_mono_repeat;
	g_glevent_funcs[3] = event_release;
	return (1);
}
