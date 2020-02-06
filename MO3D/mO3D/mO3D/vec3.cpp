#include "pch.h"
#include "vec3.h"

using namespace mo3d;

mo3d::vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

vec3::vec3(const vec3& _vec3) :vec3(_vec3.x, _vec3.y, _vec3.z)
{
}