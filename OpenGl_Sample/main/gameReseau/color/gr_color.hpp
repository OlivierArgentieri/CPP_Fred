#pragma once
#include <GLFW/glfw3.h>

struct gr_color
{
public:
	GLclampf r;
	GLclampf g;
	GLclampf b;
	GLclampf a;

	gr_color(float _r, float _g, float _b, float _a);
	gr_color();
	gr_color(const gr_color& _color);
};
