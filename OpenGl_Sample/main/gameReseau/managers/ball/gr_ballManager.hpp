#pragma once
#include <vector>

class gr_ball;

class gr_ballManager
{
private:
	static gr_ballManager* instance;

	std::vector<gr_ball*> balls;

	~gr_ballManager();
	
public:
	static gr_ballManager* getInstance();
	void addBalls(gr_ball _ball);

	void addBalls(gr_ball* _ball);	
	void clear();
	void deleteAll();
};
