#include "pch.h"
#include "vec2.h"

using namespace  mo3d;

const vec2 vec2::zero(0, 0);
const vec2 vec2::one(1, 1);
const vec2 vec2::up(0, 1);
const vec2 vec2::down(0, -1);
const vec2 vec2::left(-1, 0);
const vec2 vec2::right(1, 0);

vec2::vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}

vec2::vec2(const vec2& _vec2) : vec2(_vec2.x, _vec2.y)
{
}

float vec2::Dot(vec2 _vec) const
{
	return x * _vec.x + y * _vec.y;
}

float vec2::Dot(vec2 _vec1, vec2 _vec2)
{
	return _vec1.x * _vec2.x + _vec1.y * _vec2.y;
}

float vec2::Magnitude(vec2 _vec)
{
	return sqrt(_vec.x * _vec.x + _vec.y * _vec.y);
}

float vec2::Magnitude() const
{
	return sqrt(x*x + y * y);
}

vec2 vec2::Normalize()
{
	float _magnitude = Magnitude();

	if (_magnitude > 0)
		*this = *this / _magnitude;
	else
		*this = new vec2();
	return *this;
}

float vec2::Distance(vec2 _vec) const
{
	return (*this - _vec).Magnitude();
}

vec2 vec2::Normalize(vec2 _vec)
{
	float _magnitude = Magnitude(_vec);
	if (_magnitude > 0)
		return _vec / _magnitude;
	return vec2();
}

float vec2::Distance(vec2 _vec1, vec2 _vec2)
{
	return (_vec1 - _vec2).Magnitude();
}


vec2 vec2::operator/(float _value) const
{
	if (_value > 0)
		return vec2(x / _value, y / _value);
	return vec2::zero;
}

vec2 vec2::operator/(vec2 _vec) const
{
	float _magnitude = Magnitude(_vec);
	if (_vec != vec2::zero)
		return _vec / _magnitude;
	return vec2::zero;
}

bool vec2::operator==(vec2 _vec) const
{
	return this->x == _vec.x && this->y == _vec.y;
}

bool vec2::operator!=(vec2 _vec) const
{
	return !(*this == _vec);
}

vec2* vec2::operator=(vec2* _vec)
{
	this->x = _vec->x;
	this->y = _vec->y;
	return this;
}

vec2 vec2::operator+(vec2 _vec) const
{
	return vec2(x+_vec.x, y + _vec.y);
}

vec2 vec2::operator-(vec2 _vec) const
{
	return vec2(x - _vec.x, y - _vec.y);
}