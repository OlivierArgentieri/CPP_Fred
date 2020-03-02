#include "gr_color.hpp"

gr_color::gr_color(float _r, float _g, float _b, float _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}

gr_color::gr_color(float _r, float _g, float _b) : gr_color(_r, _g, _b, 1)
{
}

gr_color::gr_color() : gr_color(0,0,0,0)
{
	
}

gr_color::gr_color(const gr_color& _color) : gr_color(_color.r, _color.g, _color.b, _color.a)
{
}
