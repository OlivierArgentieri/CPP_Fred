#include "gr_ballManager.hpp"

#include "main/gameReseau/gameObject/ball/gr_ball.hpp"
#include "main/gameReseau/util/gr_util.hpp"
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
	gr_ball _temp = gr_ball(_ball);
	balls.push_back(_temp);
}

void gr_ballManager::makeSpawn(unsigned _nbItem, float _minPositionX, float _maxPositionX, float _minPositionY, float _maxPositionY, float _minPositionZ, float _maxPositionZ)
{
	for (int i = 0; i < _nbItem; ++i)
	{
		//get random position
		gr_ball _ballToAdd = gr_ball(glm::vec3(gr_util::getRandomRange(_minPositionX, _maxPositionX), gr_util::getRandomRange(_minPositionY, _maxPositionY), gr_util::getRandomRange(_minPositionZ, _maxPositionZ)), glm::vec3(), glm::vec3(), "aa.dds", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(gr_util::getRandomRange(0,1), gr_util::getRandomRange(0, 1), gr_util::getRandomRange(0, 1)));
		balls.push_back(_ballToAdd);
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

std::vector<gr_ball> gr_ballManager::GetAllBall()
{
	std::vector<gr_ball> _toReturn;

	for (int i = 0; i < balls.size(); ++i)
	{
		_toReturn.push_back(balls[i]);
	}

	return balls;
}
