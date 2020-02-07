#include "pch.h"
#include "UnitTest.h"
#include <cassert>
#include "vec2.h"



#define EPSILON 0.00001
#define ASSERT_EPSILON(givenVal, approxVal) assert((givenVal - approxVal) < EPSILON)
using namespace mo3d;



void UnitTest::TestVec2(float _x = 0, float _y = 0)
{
	vec2 _vec2;
	assert(_vec2.x == 0);
	assert(_vec2.y == 0);

	_vec2 = vec2(_x, _y);
	assert(_vec2.x == _x);
	assert(_vec2.y == _y);

	_vec2 = vec2(0.1234567f, 0.1234567f);
	ASSERT_EPSILON(_vec2.y, 10);
}

void UnitTest::TestVec3(float _x = 0, float _y = 0, float _z = 0)
{
	
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
}
