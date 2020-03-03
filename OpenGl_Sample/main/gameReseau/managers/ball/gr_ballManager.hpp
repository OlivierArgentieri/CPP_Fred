#pragma once
#include <vector>

class gr_ball;

class gr_ballManager
{
private:
	static gr_ballManager* instance;

	std::vector<gr_ball> balls;

	~gr_ballManager();
	
public:
	
	static gr_ballManager* getInstance();
	void addBalls(gr_ball _ball);
	void makeSpawn(unsigned _nbItem, float _minPositionX, float _maxPositionX, float _minPositionY, float _maxPositionY, float
	               _minPositionZ, float _maxPositionZ);
	void clear();
	void deleteAll();

	std::vector<gr_ball> GetAllBall();
};
