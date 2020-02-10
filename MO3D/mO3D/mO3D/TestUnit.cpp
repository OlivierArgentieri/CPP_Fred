#include "pch.h"
#include "UnitTest.h"
#include <cassert>
#include "vec2.h"
#include "vec3.h"

using namespace mo3d;

#define EPSILON 0.00001f
#define ASSERT_EPSILON(givenVal, approxVal) assert((givenVal - approxVal) < EPSILON && (givenVal - approxVal) > -EPSILON)



void UnitTest::TestVec2(float _x = 0, float _y = 0)
{
	vec2 _vec2;
	assert(_vec2.x == 0);
	assert(_vec2.y == 0);

	_vec2 = vec2(_x, _y);
	assert(_vec2.x == _x);
	assert(_vec2.y == _y);

	_vec2 = vec2(0.1234567f, 0.1234567f);
	ASSERT_EPSILON(_vec2.y, .1234567f);
}

void UnitTest::TestVec3(float _x = 0, float _y = 0, float _z = 0)
{
	vec3 _vec;
	assert(_vec.x == 0);
	assert(_vec.y == 0);
	assert(_vec.z == 0);

	_vec = vec3(_x, _y, _z);
	assert(_vec.x == _x);
	assert(_vec.y == _y);
	assert(_vec.z == _z);

	// test Magnitude : normalize
	vec3 _v1 = vec3(0, 0, 0);
	vec3 _v2 = vec3(-1, 0, 0);

	assert(_v1.Magnitude() == 0);
	assert(_v1.Magnitude() == 0);
	assert(_v2.Magnitude() == 1);
	assert(_v1.Magnitude() == vec3::Magnitude(_v1));
	assert(_v2.Magnitude() == vec3::Magnitude(_v2));
	assert(_v2.Normalize() == vec3(-1,0,0));
	assert(_v2.Normalize() != _v1);
}

void UnitTest::TestVec4(float _x = 0, float _y = 0, float _z = 0, float _w = 0)
{
	
}

UnitTest::UnitTest()
{
}

void UnitTest::Run()
{
	TestVec2();
	TestVec3();
}
