#include "pch.h"
#include "vec4.h"

using namespace mo3d;


const vec4 vec4::zero(0, 0, 0, 0);
const vec4 vec4::one(1, 1, 1, 1);


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

float vec4::Distance(vec4 _vec1, vec4 _vec2)
{
	return (_vec1 - _vec2).Magnitude();
}

float vec4::Dot(vec4 _vec) const
{
	return x * _vec.x + y * _vec.y + z * _vec.z + w * _vec.w;
}

float vec4::Distance(vec4 _vec) const
{
	return (*this - _vec).Magnitude();
}

float vec4::Magnitude(vec4 _vec)
{
	return sqrt(_vec.x * _vec.x + _vec.y * _vec.y + _vec.z * _vec.z + _vec.w * _vec.w);
}

float vec4::Magnitude() const
{
	return sqrt(x * x + y * y + z * z + w * w);
}

vec4 vec4::Normalize(vec4 _vec)
{
	float _magnitude = Magnitude(_vec);
	if (_magnitude > 0)
		return _vec / _magnitude;
	return  vec4();
}

vec4& vec4::Normalize()
{
	float _magnitude = Magnitude();

	if (_magnitude > 0)
		*this = *this / _magnitude;
	else
		*this = vec4();
	return *this;
}


vec4 vec4::operator/(float _value) const
{
	if (_value > 0)
		return vec4(x / _value, y / _value, z / _value, w/ _value);
	return vec4::zero;
}

vec4 vec4::operator/(const vec4& _vec) const
{
	if (_vec != vec4::zero)
		return vec4(x / _vec.x, y / _vec.y, z / _vec.z, w / _vec.w);
	return vec4::zero;
}

bool vec4::operator==(const vec4& _vec) const
{
	return x == _vec.x && y == _vec.y && z == _vec.z && w == _vec.w;
}

bool vec4::operator!=(const vec4& _vec) const
{
	return !(*this == _vec);
}


vec4 vec4::operator+(const vec4& _vec) const
{
	return vec4(x + _vec.x, y + _vec.y, z + _vec.z, w + _vec.w);
}

vec4 vec4::operator-(const vec4& _vec) const
{
	return vec4(x - _vec.x, y - _vec.y, z - _vec.z, w - _vec.w);
}

vec4 vec4::operator*(const vec4& _vec) const
{
	return vec4(x * _vec.x, y * _vec.y, z * _vec.z, w * _vec.w);
}

bool vec4::operator<(const vec4& _vec) const
{
	return Magnitude() < _vec.Magnitude();
}

bool vec4::operator<=(const vec4& _vec) const
{
	return Magnitude() <= _vec.Magnitude();
}

bool vec4::operator>(const vec4& _vec) const
{
	return Magnitude() > _vec.Magnitude();
}

bool vec4::operator>=(const vec4& _vec) const
{
	return Magnitude() >= _vec.Magnitude();
}

vec4& vec4::operator=(const vec4& _vec)
{
	x = _vec.x;
	y = _vec.y;
	z = _vec.z;
	w = _vec.w;
	return *this;
}

vec4& vec4::operator+=(const vec4& _vec)
{
	x += _vec.x;
	y += _vec.y;
	z += _vec.z;
	w += _vec.w;
	return *this;
}

vec4& vec4::operator-=(const vec4& _vec)
{
	x -= _vec.x;
	y -= _vec.y;
	z -= _vec.z;
	w -= _vec.w;
	return *this;
}

vec4& vec4::operator*=(const vec4& _vec)
{
	x *= _vec.x;
	y *= _vec.y;
	z *= _vec.z;
	w *= _vec.w;
	return *this;
}

vec4& vec4::operator/=(const vec4& _vec)
{
	x /= _vec.x;
	y /= _vec.y;
	z /= _vec.z;
	w /= _vec.w;
	return *this;
}