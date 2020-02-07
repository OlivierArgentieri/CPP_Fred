#include "pch.h"
#include "vec3.h"

using namespace mo3d;

mo3d::vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

vec3::vec3(const vec3& _vec3) : vec3(_vec3.x, _vec3.y, _vec3.z)
{
}

float vec3::Dot(vec3 _vec)
{
	return x * _vec.x + y * _vec.y + z * _vec.z;
}

float vec3::Dot(vec3 _vec1, vec3 _vec2)
{
	return _vec1.x * _vec2.x + _vec1.y * _vec2.y + _vec1.z * _vec2.z;
}

vec3 vec3::Cross(vec3 _vec1, vec3 _vec2)
{
	float _x = _vec1.y * _vec2.z - _vec2.y * _vec1.z;
	float _y = _vec1.z * _vec2.x - _vec2.z * _vec1.x;
	float _z = _vec1.x * _vec2.y + _vec2.x * _vec1.y;


	return vec3(_x, _y, _z);
}

vec3 vec3::Cross(vec3 _vec)
{
	float _x = y * _vec.z - _vec.y * z;
	float _y = z * _vec.x - _vec.z * x;
	float _z = x * _vec.y + _vec.x * y;


	return vec3(_x, _y, _z);

}