#pragma once

static class UnitTest
{
private:
	static void TestVec2(float _x, float _y);
	static void TestVec3(float _x, float _y, float _z);
	static void TestVec4(float _x, float _y, float _z, float _w);
	static void TestMat4();
	UnitTest();

public:
	static void Run();
	
};