#include <lgkh.h>
#include <libglKH_global_variables.h>

void my_key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	(void)window;
	(void)scancode;
	(void)mode;
	if (action == GLFW_PRESS)
		g_glkeys_states[key] = 1;
	else if (action == GLFW_RELEASE)
		g_glkeys_states[key] = 0;
}