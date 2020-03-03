#include "gr_ballManager.hpp"

#include "main/gameReseau/gameObject/ball/gr_ball.hpp"
gr_ballManager* gr_ballManager::instance = nullptr;


gr_ballManager::~gr_ballManager()
{
	delete instance;
}

gr_ballManager* gr_ballManager::getInstance()
{
	if (instance == nullptr)
		instance = new gr_ballManager();

	return instance;
}

void gr_ballManager::addBalls(gr_ball _ball)
{
	gr_ball* _temp = new gr_ball(_ball);
	balls.push_back(_temp);
}

auto gr_ballManager::makeSpawn(unsigned _nbItem) -> void
{
	for (int i = 0; i < _nbItem; ++i)
	{
		//todo
	}
}

void gr_ballManager::clear()
{
	balls.clear();
}


void gr_ballManager::deleteAll()
{
	for (int i = 0; i < balls.size() ; ++i)
	{
		delete &balls[i];
	}
}