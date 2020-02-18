#include "pch.h"
#include "vec3.h"

using namespace mo3d;

const vec3 vec3::zero(0, 0, 0);
const vec3 vec3::one(1, 1, 1);
const vec3 vec3::forward(0, 0, 1);
const vec3 vec3::up(0, 1, 0);
const vec3 vec3::down(0, -1, 0);
const vec3 vec3::right(1, 0,0);
const vec3 vec3::left(-1, 0,0);

mo3d::vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

vec3::vec3(const vec3& _vec3) : vec3(_vec3.x, _vec3.y, _vec3.z)
{
}

float vec3::Dot(vec3 _vec) const
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

float vec3::Distance(vec3 _vec1, vec3 _vec2)
{
	return (_vec1 - _vec2).Magnitude();
}

vec3 vec3::Cross(vec3 _vec) const
{
	float _x = y * _vec.z - _vec.y * z;
	float _y = z * _vec.x - _vec.z * x;
	float _z = x * _vec.y - _vec.x * y;

	return vec3(_x, _y, _z);
}

float vec3::Distance(vec3 _vec) const
{
	return (*this - _vec).Magnitude();
}

float vec3::Magnitude(vec3 _vec)
{
	return sqrt(_vec.x * _vec.x + _vec.y * _vec.y + _vec.z * _vec.z);
}

float vec3::Magnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

vec3 vec3::Normalize(vec3 _vec)
{
	float _magnitude = Magnitude(_vec);
	if(_magnitude >0)
		return _vec / _magnitude;
	return  vec3();
}

vec3& vec3::Normalize()
{
	float _magnitude = Magnitude();

	if (_magnitude > 0)
		*this = *this / _magnitude;
	else
	*this = vec3();
	return *this;
}

vec3 vec3::operator/(float _value) const
{
	if(_value > 0)
		return vec3(x / _value, y / _value, z / _value);
	return vec3::zero;
}

vec3 vec3::operator/(const vec3& _vec) const
{
	if (_vec != vec3::zero)
		return vec3(x / _vec.x, y / _vec.y, z / _vec.z);
	return vec3::zero;
}

vec3 vec3::operator*(const vec3& _vec) const
{
	return vec3(x * _vec.x, y * _vec.y, z * _vec.z);
}

bool vec3::operator==(const vec3& _vec) const
{
	return x == _vec.x && y == _vec.y && z == _vec.z;
}

bool vec3::operator!=(const vec3& _vec) const
{
	return !(*this == _vec);
}

vec3 vec3::operator+(const vec3& _vec) const
{
	return vec3(x + _vec.x, y + _vec.y, z + _vec.z);
}

bool vec3::operator<(const vec3& _vec) const
{
	return Magnitude() < _vec.Magnitude();
}

bool vec3::operator<=(const vec3& _vec) const
{
	return Magnitude() <= _vec.Magnitude();
}

bool vec3::operator>(const vec3& _vec) const
{
	return Magnitude() > _vec.Magnitude();
}

bool vec3::operator>=(const vec3& _vec) const
{
	return Magnitude() >= _vec.Magnitude();
}

vec3& vec3::operator=(const vec3& _vec)
{
	x = _vec.x;
	y = _vec.y;
	z = _vec.z;
	return *this;
}

vec3& vec3::operator+=(const vec3& _vec)
{
	x += _vec.x;
	y += _vec.y;
	z += _vec.z;
	return *this;
}

vec3& vec3::operator-=(const vec3& _vec)
{
	x -= _vec.x;
	y -= _vec.y;
	z -= _vec.z;
	return *this;
}

vec3& vec3::operator*=(const vec3& _vec)
{

	x *= _vec.x;
	y *= _vec.y;
	z *= _vec.z;
	return *this;
}

vec3& vec3::operator/=(const vec3& _vec)
{
	x /= _vec.x;
	y /= _vec.y;
	z /= _vec.z;
	return *this;
}

vec3 vec3::operator-(const vec3& _vec) const
{
	return vec3(x - _vec.x, y - _vec.y, z - _vec.z);
}