#ifndef LIBGLKH_H
#define LIBGLKH_H
#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <libglKH_global_variables.h>
#include <libglKH_global_structs.h>

char	key_handler_init(GLFWwindow* window);

char	key_handler_add(size_t key, t_click_type click_type, void* args,
					char (*condition)(void), void (*reaction)(void*));

void	key_handle(double time);

#endif
