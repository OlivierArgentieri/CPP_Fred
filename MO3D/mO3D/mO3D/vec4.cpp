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

float vec4::Dot(vec4 _vec1, vec4 _vec2)
{
	return _vec1.x * _vec2.x + _vec1.y * _vec2.y + _vec1.z * _vec2.z + _vec1.w + _vec2.w;
}

float vec4::Dot(vec4 _vec)
{
	return x * _vec.x + y * _vec.y + z * _vec.z + w + _vec.w;
}
