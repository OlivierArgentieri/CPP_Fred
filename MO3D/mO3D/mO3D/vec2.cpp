#include "pch.h"
#include "vec2.h"

using namespace  mo3d;

vec2::vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}

vec2::vec2(const vec2& _vec2) : vec2(_vec2.x, _vec2.y)
{
}

float vec2::Dot(vec2 _vec)
{
	return x * _vec.x + y * _vec.y;
}

float vec2::Dot(vec2 _vec1, vec2 _vec2)
{
	return _vec1.x * _vec2.x + _vec1.y * _vec2.y;
}