#include "pch.h"
#include "vec4.h"

using namespace mo3d;

vec4::vec4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}


vec4::vec4(const vec4& _vec4) : vec4(_vec4.x, _vec4.y, _vec4.z, _vec4.w)
{
}