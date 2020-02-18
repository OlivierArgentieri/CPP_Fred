#pragma once

static class UnitTest
{
private:
	static void TestVec2(float _x, float _y);
	static void TestVec2Constructor(float _x, float _y);
	static void TestVec2Epsilon();
	static void TestVec2Magnitude();
	static void TestVec2Normalize();
	static void TestVec2Distance();
	static void TestVec2Dot();
	static void TestVec2Mul();
	static void TestVec2SetValue();
	static void TestVec2Div();
	static void TestVec2Addition();
	static void TestVec2Subtraction();
	static void TestVec2Equals();
	static void TestVec2NotEquals();
	static void TestVec2Superior();
	static void TestVec2SuperiorEquals();
	static void TestVec2Inferior();
	static void TestVec2InferiorEquals();


	static void TestVec3(float _x, float _y, float _z);
	static void TestVec3Constructor(float _x, float _y, float _z);
	static void TestVec3Epsilon();
	static void TestVec3Magnitude();
	static void TestVec3Normalize();
	static void TestVec3Distance();
	static void TestVec3Cross();
	static void TestVec3Dot();
	static void TestVec3Mul();
	static void TestVec3SetValue();
	static void TestVec3Div();
	static void TestVec3Addition();
	static void TestVec3Subtraction();
	static void TestVec3Equals();
	static void TestVec3NotEquals();
	static void TestVec3Superior();
	static void TestVec3SuperiorEquals();
	static void TestVec3Inferior();
	static void TestVec3InferiorEquals();



	static void TestVec4(float _x, float _y, float _z, float _w);
	static void TestVec4Constructor(float _x, float _y, float _z, float _w);
	static void TestVec4Epsilon();
	static void TestVec4Magnitude();
	static void TestVec4Normalize();
	static void TestVec4Distance();
	static void TestVec4Dot();
	static void TestVec4Mul();
	static void TestVec4SetValue();
	static void TestVec4Div();
	static void TestVec4Addition();
	static void TestVec4Subtraction();
	static void TestVec4Equals();
	static void TestVec4NotEquals();
	static void TestVec4Superior();
	static void TestVec4SuperiorEquals();
	static void TestVec4Inferior();
	static void TestVec4InferiorEquals();
	
	static void TestMat4();
	static void TestMat4Transpose();
	static void TestMat4Determinant();
	static void TestMat4Identity();
	static void TestMat4Mul();
	static void TestMat4Subtraction();
	static void TestMat4Addition();


	UnitTest();

public:
	static void Run();
	
};