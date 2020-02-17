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


#pragma region vec2
void UnitTest::TestVec2(float _x = 0, float _y = 1)
{
	
	TestVec2Constructor(_x, _y);
	TestVec2Epsilon();
	TestVec2Normalize();
	TestVec2Distance();

	TestVec2Dot();
	
	TestVec2Mul();
	TestVec2Div();
	TestVec2Addition();
	TestVec2Subtraction();
	
	TestVec2Equals();
	TestVec2NotEquals();
	TestVec2Superior();
	TestVec2SuperiorEquals();
	TestVec2Inferior();
	TestVec2InferiorEquals();

}

void UnitTest::TestVec2Constructor(float _x = 0, float _y = 1)
{
	vec2 _vec1;
	assert(_vec1.x == 0);
	assert(_vec1.y == 0);

	vec2 _vec2 = vec2(_x, _y);
	assert(_vec2.x == _x);
	assert(_vec2.y == _y);
}

void UnitTest::TestVec2Epsilon()
{
	vec2 _vec1 = vec2(0.1234567f, 0.1234567f);
	ASSERT_EPSILON(_vec1.y, .1234567f);
	ASSERT_EPSILON(_vec1.x, .1234567f);
}

void UnitTest::TestVec2Magnitude()
{
	vec2 _v1 = vec2(0, 0);
	vec2 _v2 = vec2(-1, 0);

	assert(_v1.Magnitude() == 0);
	assert(_v2.Magnitude() == 1);
	assert(_v1.Magnitude() == vec2::Magnitude(_v1));
	assert(_v2.Magnitude() == vec2::Magnitude(_v2));
}

void UnitTest::TestVec2Normalize()
{
	vec2 _v1 = vec2(0, 0);
	vec2 _v2 = vec2(-1, 0);
	vec2 _v3 = vec2(2, 0);

	assert(_v1.Normalize() == vec2(0, 0));
	assert(_v2.Normalize() == vec2(-1, 0));
	assert(_v3.Normalize() == vec2(1, 0));
}

void UnitTest::TestVec2Distance()
{
	vec2 _v1 = vec2(0, 0);
	vec2 _v2 = vec2(-1, 0);
	vec2 _v3 = vec2(2, 0);

	assert(_v1.Distance(_v2) == 1);
	assert(_v1.Distance(_v3) == 2);
	assert(_v1.Distance(_v1) == 0);
}

void UnitTest::TestVec2Dot()
{
	vec2 _v1 = vec2(1, 0);
	vec2 _v2 = vec2(0, 1);
	
	vec2 _v3 = vec2(1, 1);
	vec2 _v4 = vec2(5, 5);

	assert(_v1.Dot(_v2) == 0);
	assert(_v3.Dot(_v4) == 10);
}

void UnitTest::TestVec2Mul()
{
	vec2 _v1 = vec2(2, 3);
	vec2 _v2 = vec2(5, 5);
	_v1 * _v2;
	
	assert(_v1 == vec2(2, 3));
	assert(_v2 == vec2(5, 5));
	assert(_v1 * _v2 == vec2(10, 15));

	_v1 *= _v2;
	assert(_v1 == vec2(10, 15));

}

void UnitTest::TestVec2Div()
{
	vec2 _v1 = vec2(2, 3);
	vec2 _v2 = vec2(5, 5);
	_v1 / _v2;

	assert(_v1 == vec2(2, 3));
	assert(_v2 == vec2(5, 5));
	assert((_v1 / _v2) == vec2(0.4f, 0.6f));

	_v1 /= _v2;
	assert(_v1 == vec2(0.4f, 0.6f));

}

void UnitTest::TestVec2Addition()
{
	vec2 _v1 = vec2(2, 3);
	vec2 _v2 = vec2(5, 5);
	_v1 + _v2;

	assert(_v1 == vec2(2, 3));
	assert(_v2 == vec2(5, 5));
	assert((_v1 + _v2) == vec2(7, 8));

	_v1 += _v2;
	assert(_v1 == vec2(7, 8));
}

void UnitTest::TestVec2Subtraction()
{
	vec2 _v1 = vec2(2, 3);
	vec2 _v2 = vec2(5, 5);
	_v1 - _v2;

	assert(_v1 == vec2(2, 3));
	assert(_v2 == vec2(5, 5));
	assert((_v1 - _v2) == vec2(-3, -2));

	_v1 -= _v2;
	assert(_v1 == vec2(-3, -2));

}

void UnitTest::TestVec2Equals()
{
	vec2 _v1 = vec2(2, 3);
	vec2 _v2 = vec2(2, 3);
	_v1 == _v2;

	assert(_v1 == vec2(2, 3));
	assert(_v2 == vec2(2, 3));
	assert(_v1 == _v2);
}

void UnitTest::TestVec2NotEquals()
{
	vec2 _v1 = vec2(2, 3);
	vec2 _v2 = vec2(2, 4);
	_v1 != _v2;

	assert(_v1 == vec2(2, 3));
	assert(_v2 == vec2(2, 4));
	assert(_v1 != _v2);
}

void UnitTest::TestVec2Superior()
{
	vec2 _v1 = vec2(2, 7);
	vec2 _v2 = vec2(2, 4);
	_v1 > _v2;

	assert(_v1 == vec2(2, 7));
	assert(_v2 == vec2(2, 4));
	assert(_v1 > _v2);
}

void UnitTest::TestVec2SuperiorEquals()
{
	vec2 _v1 = vec2(2, 7);
	vec2 _v2 = vec2(2, 4);
	vec2 _v3 = vec2(2, 4);
	_v1 > _v2;

	assert(_v1 == vec2(2, 7));
	assert(_v2 == vec2(2, 4));
	assert(_v1 >= _v2);
	assert(_v1 >= _v3);
}

void UnitTest::TestVec2Inferior()
{
	vec2 _v1 = vec2(2, 4);
	vec2 _v2 = vec2(2, 7);
	_v1 < _v2;

	assert(_v1 == vec2(2, 4));
	assert(_v2 == vec2(2, 7));
	assert(_v1 < _v2);
}

void UnitTest::TestVec2InferiorEquals()
{
	vec2 _v1 = vec2(2, 4);
	vec2 _v2 = vec2(2, 4);
	_v1 <= _v2;

	assert(_v1 == vec2(2, 4));
	assert(_v2 == vec2(2, 4));
	assert(_v1 <= _v2);
}
#pragma endregion

#pragma region vec3
void UnitTest::TestVec3(float _x = 0, float _y = 0, float _z = 0)
{
	TestVec3Constructor(_x, _y, _z);
	TestVec3Epsilon();
	TestVec3Normalize();
	TestVec3Distance();
		   
	TestVec3Dot();
		   
	TestVec3Mul();
	TestVec3Div();
	TestVec3Addition();
	TestVec3Subtraction();
		   
	TestVec3Equals();
	TestVec3NotEquals();
	TestVec3Superior();
	TestVec3SuperiorEquals();
	TestVec3Inferior();
	TestVec3InferiorEquals();
}

void UnitTest::TestVec3Constructor(float _x = 0, float _y = 1, float _z = -1)
{
	vec3 _vec1;
	assert(_vec1.x == 0);
	assert(_vec1.y == 0);
	assert(_vec1.z == 0);

	vec3 _vec2 = vec3(_x, _y, _z);
	assert(_vec2.x == _x);
	assert(_vec2.y == _y);
	assert(_vec2.z == _z);
}

void UnitTest::TestVec3Epsilon()
{
	vec3 _vec1 = vec3(0.1234567f, 0.1234567f, 0.1234567f);
	ASSERT_EPSILON(_vec1.x, .1234567f);
	ASSERT_EPSILON(_vec1.y, .1234567f);
	ASSERT_EPSILON(_vec1.z, .1234567f);
}

void UnitTest::TestVec3Magnitude()
{
	vec3 _v1 = vec3(0, 0, 0);
	vec3 _v2 = vec3(-1, 0, 0);

	assert(_v1.Magnitude() == 0);
	assert(_v2.Magnitude() == 1);
	assert(_v1.Magnitude() == vec3::Magnitude(_v1));
	assert(_v2.Magnitude() == vec3::Magnitude(_v2));
}

void UnitTest::TestVec3Normalize()
{
	vec3 _v1 = vec3(0, 0, 0);
	vec3 _v2 = vec3(-1, -1, -1);
	vec3 _v3 = vec3(2, 2, 2);

	assert(_v1.Normalize().Magnitude() == 0);
	vec3 _testNorm = _v3.Normalize();
	ASSERT_EPSILON(_testNorm.Magnitude(), 1);
	ASSERT_EPSILON(_v2.Normalize().Magnitude(), 1);
}

void UnitTest::TestVec3Distance()
{
	vec3 _v1 = vec3(0, 0, 0);
	vec3 _v2 = vec3(-1, 0, 0);
	vec3 _v3 = vec3(2, 0, 0);

	assert(_v1.Distance(_v2) == 1);
	assert(_v1.Distance(_v3) == 2);
	assert(_v1.Distance(_v1) == 0);
}

void UnitTest::TestVec3Cross()
{
	vec3 _v1 = vec3(1, 1, 1);
	vec3 _v2 = vec3(1, 1, 1);

	assert(_v1.Cross(_v2) == 0);
}

void UnitTest::TestVec3Dot()
{
	vec3 _v1 = vec3(1, 0,0);
	vec3 _v2 = vec3(0, 1, 0);

	vec3 _v3 = vec3(1, 2, 3);
	vec3 _v4 = vec3(1, 4, 5);

	assert(_v1.Dot(_v2) == 0);
	assert(_v3.Dot(_v4) == 24);
}

void UnitTest::TestVec3Mul()
{
	vec3 _v1 = vec3(2, 3, 4); 
	vec3 _v2 = vec3(5, 5, 5);
	_v1 * _v2;

	assert(_v1 == vec3(2, 3, 4));
	assert(_v2 == vec3(5, 5, 5));
	assert(_v1 * _v2 == vec3(10, 15, 20));

	_v1 *= _v2;
	assert(_v1 == vec3(10, 15, 20));
}

void UnitTest::TestVec3Div()
{
	vec3 _v1 = vec3(2, 3, 4);
	vec3 _v2 = vec3(5, 5, 5);
	_v1 / _v2;

	assert(_v1 == vec3(2, 3, 4));
	assert(_v2 == vec3(5, 5, 5));
	assert((_v1 / _v2) == vec3(0.4f, 0.6f, 0.8f));

	_v1 /= _v2;
	assert(_v1 == vec3(0.4f, 0.6f, 0.8f));

}

void UnitTest::TestVec3Addition()
{
	vec3 _v1 = vec3(2, 3, 4);
	vec3 _v2 = vec3(5, 5, 5);
	_v1 + _v2;

	assert(_v1 == vec3(2, 3, 4));
	assert(_v2 == vec3(5, 5, 5));
	assert((_v1 + _v2) == vec3(7, 8, 9));

	_v1 += _v2;
	assert(_v1 == vec3(7, 8, 9));
}

void UnitTest::TestVec3Subtraction()
{
	vec3 _v1 = vec3(2, 3, 4);
	vec3 _v2 = vec3(5, 5, 5);
	_v1 - _v2;

	assert(_v1 == vec3(2, 3, 4));
	assert(_v2 == vec3(5, 5, 5));
	assert((_v1 - _v2) == vec3(-3, -2, -1));

	_v1 -= _v2;
	assert(_v1 == vec3(-3, -2, -1));
}

void UnitTest::TestVec3Equals()
{
	vec3 _v1 = vec3(2, 3, 4);
	vec3 _v2 = vec3(2, 3, 4);
	_v1 == _v2;

	assert(_v1 == vec3(2, 3, 4));
	assert(_v2 == vec3(2, 3, 4));
	assert(_v1 == _v2);
}

void UnitTest::TestVec3NotEquals()
{
	vec3 _v1 = vec3(2, 3, 4);
	vec3 _v2 = vec3(2, 4, 5);
	_v1 != _v2;

	assert(_v1 == vec3(2, 3, 4));
	assert(_v2 == vec3(2, 4, 5));
	assert(_v1 != _v2);
}

void UnitTest::TestVec3Superior()
{
	vec3 _v1 = vec3(2, 7, 0);
	vec3 _v2 = vec3(2, 4, 0);
	_v1 > _v2;

	assert(_v1 == vec3(2, 7, 0));
	assert(_v2 == vec3(2, 4, 0));
	assert(_v1 > _v2);
}

void UnitTest::TestVec3SuperiorEquals()
{
	vec3 _v1 = vec3(2, 7, 8);
	vec3 _v2 = vec3(2, 4, 4);
	vec3 _v3 = vec3(2, 4, 4);
	_v1 > _v2;

	assert(_v1 == vec3(2, 7, 8));
	assert(_v2 == vec3(2, 4, 4));
	assert(_v1 >= _v2);
	assert(_v1 >= _v3);
}

void UnitTest::TestVec3Inferior()
{
	vec3 _v1 = vec3(2, 4, 4);
	vec3 _v2 = vec3(2, 7, 8);
	_v1 < _v2;

	assert(_v1 == vec3(2, 4, 4));
	assert(_v2 == vec3(2, 7, 8));
	assert(_v1 < _v2);
}

void UnitTest::TestVec3InferiorEquals()
{
	vec3 _v1 = vec3(2, 4, 4);
	vec3 _v2 = vec3(2, 4, 4);
	_v1 <= _v2;

	assert(_v1 == vec3(2, 4, 4));
	assert(_v2 == vec3(2, 4, 4));
	assert(_v1 <= _v2);
}
#pragma endregion 

#pragma region vec4
void UnitTest::TestVec4(float _x = 0, float _y = 0, float _z = 0, float _w = 0)
{
	TestVec4Constructor(_x, _y, _z, _w);
	TestVec4Epsilon();
	TestVec4Normalize();
	TestVec4Distance();

	TestVec4Dot();

	TestVec4Mul();
	TestVec4Div();
	TestVec4Addition();
	TestVec4Subtraction();

	TestVec4Equals();
	TestVec4NotEquals();
	TestVec4Superior();
	TestVec4SuperiorEquals();
	TestVec4Inferior();
	TestVec4InferiorEquals();
	TestVec4InferiorEquals();
}

void UnitTest::TestVec4Constructor(float _x = 0, float _y = 1, float _z = -1, float _w = -1)
{
	vec4 _vec1;
	assert(_vec1.x == 0);
	assert(_vec1.y == 0);
	assert(_vec1.z == 0);
	assert(_vec1.w == 0);

	vec4 _vec2 = vec4(_x, _y, _z, _w);
	assert(_vec2.x == _x);
	assert(_vec2.y == _y);
	assert(_vec2.z == _z);
	assert(_vec2.w == _w);
}

void UnitTest::TestVec4Epsilon()
{
	vec4 _vec1 = vec4(0.1234567f, 0.1234567f, 0.1234567f, 0.1234567f);
	ASSERT_EPSILON(_vec1.x, .1234567f);
	ASSERT_EPSILON(_vec1.y, .1234567f);
	ASSERT_EPSILON(_vec1.z, .1234567f);
	ASSERT_EPSILON(_vec1.w, .1234567f);
}

void UnitTest::TestVec4Magnitude()
{
	vec4 _v1 = vec4(0, 0, 0, 0);
	vec4 _v2 = vec4(-1, 0, 0, 0);

	assert(_v1.Magnitude() == 0);
	assert(_v2.Magnitude() == 1);
	assert(_v1.Magnitude() == vec4::Magnitude(_v1));
	assert(_v2.Magnitude() == vec4::Magnitude(_v2));
}

void UnitTest::TestVec4Normalize()
{
	vec4 _v1 = vec4(0, 0, 0, 0);
	vec4 _v2 = vec4(-1, -1, -1);
	vec4 _v3 = vec4(2, 2, 2);

	assert(_v1.Normalize().Magnitude() == 0);
	vec4 _testNorm = _v3.Normalize();
	ASSERT_EPSILON(_testNorm.Magnitude(), 1);
	ASSERT_EPSILON(_v2.Normalize().Magnitude(), 1);
}

void UnitTest::TestVec4Distance()
{
	vec4 _v1 = vec4(0, 0, 0, 0);
	vec4 _v2 = vec4(-1, 0, 0, 0);
	vec4 _v3 = vec4(2, 0, 0, 0);

	assert(_v1.Distance(_v2) == 1);
	assert(_v1.Distance(_v3) == 2);
	assert(_v1.Distance(_v1) == 0);
}

void UnitTest::TestVec4Dot()
{
	vec4 _v1 = vec4(1, 0, 0, 0);
	vec4 _v2 = vec4(0, 1, 0, 0);

	vec4 _v3 = vec4(1, 2, 3, 4);
	vec4 _v4 = vec4(1, 4, 5, 6);

	assert(_v1.Dot(_v2) == 0);
	assert(_v3.Dot(_v4) == 48);
}

void UnitTest::TestVec4Mul()
{
	vec4 _v1 = vec4(2, 3, 4, 5);
	vec4 _v2 = vec4(5, 5, 5, 5);
	_v1 * _v2;

	assert(_v1 == vec4(2, 3, 4, 5));
	assert(_v2 == vec4(5, 5, 5, 5));
	assert(_v1 * _v2 == vec4(10, 15, 20, 25));

	_v1 *= _v2;
	assert(_v1 == vec4(10, 15, 20, 25));
}

void UnitTest::TestVec4Div()
{
	vec4 _v1 = vec4(2, 3, 4, 5);
	vec4 _v2 = vec4(5, 5, 5, 5);
	_v1 / _v2;

	assert(_v1 == vec4(2, 3, 4, 5));
	assert(_v2 == vec4(5, 5, 5, 5));
	assert((_v1 / _v2) == vec4(0.4f, 0.6f, 0.8f, 1));

	_v1 /= _v2;
	assert(_v1 == vec4(0.4f, 0.6f, 0.8f, 1));

}

void UnitTest::TestVec4Addition()
{
	vec4 _v1 = vec4(2, 3, 4, 5);
	vec4 _v2 = vec4(5, 5, 5, 5);
	_v1 + _v2;

	assert(_v1 == vec4(2, 3, 4, 5));
	assert(_v2 == vec4(5, 5, 5, 5));
	assert((_v1 + _v2) == vec4(7, 8, 9, 10));

	_v1 += _v2;
	assert(_v1 == vec4(7, 8, 9, 10));
}

void UnitTest::TestVec4Subtraction()
{
	vec4 _v1 = vec4(2, 3, 4, 5);
	vec4 _v2 = vec4(5, 5, 5, 5);
	_v1 - _v2;

	assert(_v1 == vec4(2, 3, 4, 5));
	assert(_v2 == vec4(5, 5, 5, 5));
	assert((_v1 - _v2) == vec4(-3, -2, -1, 0));

	_v1 -= _v2;
	assert(_v1 == vec4(-3, -2, -1));
}

void UnitTest::TestVec4Equals()
{
	vec4 _v1 = vec4(2, 3, 4, 5);
	vec4 _v2 = vec4(2, 3, 4, 5);
	_v1 == _v2;

	assert(_v1 == vec4(2, 3, 4, 5));
	assert(_v2 == vec4(2, 3, 4, 5));
	assert(_v1 == _v2);
}

void UnitTest::TestVec4NotEquals()
{
	vec4 _v1 = vec4(2, 3, 4, 3);
	vec4 _v2 = vec4(2, 4, 5, 6);
	_v1 != _v2;

	assert(_v1 == vec4(2, 3, 4, 3));
	assert(_v2 == vec4(2, 4, 5, 6));
	assert(_v1 != _v2);
}

void UnitTest::TestVec4Superior()
{
	vec4 _v1 = vec4(2, 7, 0, 0);
	vec4 _v2 = vec4(2, 4, 0, 0);
	_v1 > _v2;

	assert(_v1 == vec4(2, 7));
	assert(_v2 == vec4(2, 4));
	assert(_v1 > _v2);
}

void UnitTest::TestVec4SuperiorEquals()
{
	vec4 _v1 = vec4(2, 7, 8, 0);
	vec4 _v2 = vec4(2, 4, 4,0);
	vec4 _v3 = vec4(2, 4, 4,0);
	_v1 > _v2;

	assert(_v1 == vec4(2, 7, 8,0));
	assert(_v2 == vec4(2, 4, 4,0));
	assert(_v1 >= _v2);
	assert(_v1 >= _v3);
}

void UnitTest::TestVec4Inferior()
{
	vec4 _v1 = vec4(2, 4, 4,0);
	vec4 _v2 = vec4(2, 7, 8,0);
	_v1 < _v2;

	assert(_v1 == vec4(2, 4, 4,0));
	assert(_v2 == vec4(2, 7, 8,0));
	assert(_v1 < _v2);
}

void UnitTest::TestVec4InferiorEquals()
{
	vec4 _v1 = vec4(2, 4, 4,0);
	vec4 _v2 = vec4(2, 4, 4,0);
	_v1 <= _v2;

	assert(_v1 == vec4(2, 4, 4,0));
	assert(_v2 == vec4(2, 4, 4,0));
	assert(_v1 <= _v2);
}
#pragma endregion 


void UnitTest::TestMat4()
{
	TestMat4Transpose();
	TestMat4Determinant();
	TestMat4Identity();
	TestMat4Mul();
// / - + != == 
}

void UnitTest::TestMat4Transpose()
{
	// test transpose
	float _testTranspose[4][4] =
	{
		{ 1, 0, 1, 0 },
		{ 1, 0, 1, 0 },
		{ 1, 0, 1, 0 },
		{ 1, 0, 1, 0 }
	};
	float _testTransposeRes[4][4] =
	{
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 }
	};
	mat4 _matTransposeRes = mat4(_testTransposeRes);
	mat4 _matTranspose = mat4(_testTranspose);

	_matTranspose.Transpose();
	assert(_matTranspose == _matTransposeRes);
}

void UnitTest::TestMat4Determinant()
{
	float _test[4][4] =
	{
		{ -120, -2.754, 3, 80.01 },
		{ 5, 16.2, -7.2, 747 },
		{ 28, -10, 11, 12 },
		{ 17.258, 3.14159, 315.8, -20 }
	};

	mat4 _mat = mat4(_test);
	double _a = _mat.Determinant();
	ASSERT_EPSILON(_a, 324831237.06621);
}

void UnitTest::TestMat4Identity()
{
	// test identity
	float _testIDentity[4][4] =
	{
		{ 1, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 1 }
	};

	mat4 _matID = mat4::Identity();
	mat4 _matIDTest = mat4(_testIDentity);
	assert(_matID == _matIDTest);
}

void UnitTest::TestMat4Mul()
{
	float _test[4][4] =
	{
		{ -120, -2.754, 3, 80.01 },
		{ 5, 16.2, -7.2, 747 },
		{ 28, -10, 11, 12 },
		{ 17.258, 3.14159, 315.8, -20 }
	};
	
	mat4 _matID = mat4::Identity();
	mat4 _matIDTest = mat4(_test);
	_matID * _matIDTest;

	assert(_matID == mat4::Identity());
	assert(_matIDTest == mat4(_test));
	assert(_matID * _matIDTest == _matIDTest);

	_matIDTest *= _matID;
	assert(_matIDTest == mat4(_test));
}

UnitTest::UnitTest() = default;

void UnitTest::Run()
{
	TestVec2();
	TestVec3();
	TestVec4();
	TestMat4();
}