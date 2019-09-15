#ifndef LIBGLKH_GLOBAL_STRUCTS_H
#define LIBGLKH_GLOBAL_STRUCTS_H
#define TYPE_COUNT 4

#include <stdio.h>

typedef enum		e_click_type
{
	KEY_PRESS = 1,
	KEY_REPEAT = 2,
	KEY_MONO_REPEAT = 3,
	KEY_RELEASE = 4
}					t_click_type;

typedef struct	s_key t_key;

struct				s_key
{
	char			(*condition)(void);
	void			(*reaction)(void*);
	void*			args;
	size_t			key;
	t_click_type	click_type;
	char			press_state;
	t_key*			next;
};

#endif