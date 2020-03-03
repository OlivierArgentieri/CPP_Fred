#include "gr_util.hpp"
#include <random>

float gr_util::getRandomRange(float _min, float _max)
{
	std::random_device dev;
	std::mt19937 rng(dev());

	std::uniform_real_distribution<float> dist(_min, _max);

	return dist(rng);
}