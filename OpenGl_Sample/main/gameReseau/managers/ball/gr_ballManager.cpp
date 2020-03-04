#include "gr_ballManager.hpp"

#include "main/gameReseau/gameObject/ball/gr_ball.hpp"
#include "main/gameReseau/util/gr_util.hpp"
gr_ballManager* gr_ballManager::instance = nullptr;


bool gr_ballManager::TestCollision(gr_ball *_ball)
{
	for (int i = 0; i < balls.size(); ++i)
	{
		if ((glm::distance(_ball->GetTransform().position, balls[i]->GetTransform().position)) < _ball->GetTransform().scale.x)
			return true;
	}

	return false;
}

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

void gr_ballManager::addBalls(gr_ball* _ball)
{
	balls.push_back(_ball);
}

void gr_ballManager::makeSpawn(unsigned _nbItem, float _minPositionX, float _maxPositionX, float _minPositionY, float _maxPositionY, float _minPositionZ, float _maxPositionZ)
{
	for (int i = 0; i < _nbItem; ++i)
	{
		gr_ball *_ballToAdd = new gr_ball(glm::vec3(gr_util::getRandomRange(_minPositionX, _maxPositionX), gr_util::getRandomRange(_minPositionY, _maxPositionY), gr_util::getRandomRange(_minPositionZ, _maxPositionZ)), glm::vec3(), glm::vec3(1, 1, 1), "aa.dds", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(gr_util::getRandomRange(0, 1), gr_util::getRandomRange(0, 1), gr_util::getRandomRange(0, 1)));

		do
		{
			_ballToAdd->SetPosition(glm::vec3(gr_util::getRandomRange(_minPositionX, _maxPositionX), gr_util::getRandomRange(_minPositionY, _maxPositionY), gr_util::getRandomRange(_minPositionZ, _maxPositionZ)));
		}
		while (TestCollision(_ballToAdd));
		//get random position
		balls.push_back(_ballToAdd);
	}
}

void gr_ballManager::Clear()
{
	balls.clear();
}


void gr_ballManager::DeleteAll()
{
	for (int i = 0; i < balls.size() ; ++i)
	{
		delete &balls[i];
	}
}

void gr_ballManager::Update()
{
	balls[2]->MoveRight(0, 0);
}

std::vector<gr_ball*> gr_ballManager::GetAllBall() const
{
	/*
	std::vector<gr_ball> _toReturn;

	for (int i = 0; i < balls.size(); ++i)
	{
		_toReturn.push_back(balls[i]);
	}
	*/
	return balls;
}
