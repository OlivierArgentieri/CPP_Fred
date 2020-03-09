#pragma once

class gr_util
{
	/// get a random between a[include] and b[exclude]
public:
	static float getRandomRange(float _min, float _max);

	static float clamp(float _value, float _min, float _max);
};