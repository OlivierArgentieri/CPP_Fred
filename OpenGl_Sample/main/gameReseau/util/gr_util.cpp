#include "gr_util.hpp"
#include <random>

// hardware random 
float gr_util::getRandomRange(float _min, float _max)
{
	std::random_device dev;
	std::mt19937 rng(dev());

	std::uniform_real_distribution<float> dist(_min, _max);

	return dist(rng);
}

float gr_util::clamp(float _value, float _min, float _max)
{
	return std::max(_min, std::min(_max, _value));
}