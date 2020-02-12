#include "pch.h"
#include "UnitTest.h"
#include <cassert>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"

using namespace mo3d;

#define EPSILON 0.00001f
#define ASSERT_EPSILON(givenVal, approxVal) assert((givenVal - approxVal) < EPSILON && (givenVal - approxVal) > -EPSILON)


void UnitTest::TestVec2(float _x = 0, float _y = 1)
{
	vec2 _vec2;
	assert(_vec2.x == 0);
	assert(_vec2.y == 0);

	vec2 _vec3 = vec2(_x, _y);
	assert(_vec3.x == _x);
	assert(_vec3.y == _y);

	_vec2 = vec2(0.1234567f, 0.1234567f);
	ASSERT_EPSILON(_vec2.y, .1234567f);

	// test Magnitude : normalize
	vec2 _v1 = vec2(0, 0);
	vec2 _v2 = vec2(-1, 0);

	assert(_v1.Magnitude() == 0);
	assert(_v1.Magnitude() == 0);
	assert(_v2.Magnitude() == 1);
	assert(_v1.Magnitude() == vec2::Magnitude(_v1));
	assert(_v2.Magnitude() == vec2::Magnitude(_v2));
	assert(_v2.Normalize() == vec2(-1, 0));
	assert(_v2.Normalize() != _v1);
}

void UnitTest::TestVec3(float _x = 0, float _y = 0, float _z = 0)
{
	vec3 _vec;
	assert(_vec.x == 0);
	assert(_vec.y == 0);
	assert(_vec.z == 0);

	 vec3 _vec1 = vec3(_x, _y, _z);
	assert(_vec1.x == _x);
	assert(_vec1.y == _y);
	assert(_vec1.z == _z);


	// test epsilon
	_vec = vec3(0.1234567f, 0.1234567f);
	ASSERT_EPSILON(_vec.y, .1234567f);


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
	vec4 _vec;
	assert(_vec.x == 0);
	assert(_vec.y == 0);
	assert(_vec.z == 0);
	assert(_vec.w == 0);

	vec4 _vec1 = vec4(_x, _y, _z, _w);
	assert(_vec1.x == _x);
	assert(_vec1.y == _y);
	assert(_vec1.z == _z);
	assert(_vec1.w == _w);


	// test epsilon
	_vec = vec4(0.1234567f, 0.1234567f);
	ASSERT_EPSILON(_vec.y, .1234567f);


	// test Magnitude : normalize
	vec4 _v1 = vec4(0, 0, 0);
	vec4 _v2 = vec4(-1, 0, 0);

	assert(_v1.Magnitude() == 0);
	assert(_v1.Magnitude() == 0);
	assert(_v2.Magnitude() == 1);
	assert(_v1.Magnitude() == vec4::Magnitude(_v1));
	assert(_v2.Magnitude() == vec4::Magnitude(_v2));
	assert(_v2.Normalize() == vec4(-1, 0, 0));
	assert(_v2.Normalize() != _v1);
}


void UnitTest::TestMat4()
{
	mat4 _mat = mat4::Identity();

	float _test[4][4] =
	{
		{ 10, 1, 2, 3 },
		{ 4, 5, 6, 7 },
		{ 8, 9, 10, 11 },
		{ 12, 13, 14, 20 }
	};

	_mat = mat4(_test);
	//_mat.Transpose();
	float _a = _mat.Determinant();
	mat4 _matMul = _mat * mat4::Identity();
}

UnitTest::UnitTest()
{
	
}

void UnitTest::Run()
{
	TestVec2();
	TestVec3();
	TestVec4();
	TestMat4();
}