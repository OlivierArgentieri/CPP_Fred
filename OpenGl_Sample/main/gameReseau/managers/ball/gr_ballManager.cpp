
#include "main/gameReseau/gameObject/ball/gr_ball.hpp"
#include "gr_ballManager.hpp"

#include <iostream>



#include "main/gameReseau/managers/input/gr_inputManager.hpp"

#include "main/gameReseau/util/gr_util.hpp"

#define BALL_SCALE 1
#define BALL_SPEED 5.0f

gr_ballManager* gr_ballManager::instance = nullptr;


void gr_ballManager::onMoveMainBall(glm::vec2 _axisValues)
{
	if (!mainBall || _axisValues == glm::vec2()) return;


	if (!testCollision(mainBall->getTransform().position + glm::vec3(_axisValues.x*0.1, 0, _axisValues.y*0.1), mainBall))
		mainBall->addVelocity(glm::vec3(_axisValues.x*0.1, 0, _axisValues.y*0.1));


}

::gr_ball* gr_ballManager::testCollision(glm::vec3 _position, gr_ball* _this)
{
	for (int i = 0; i < balls.size(); ++i)
	{
		if (balls[i] != _this && (glm::distance(_position, balls[i]->getTransform().position)) < balls[i]->getTransform().scale.x)
			return balls[i];
	}

	return nullptr; // ok
}

void gr_ballManager::registerToInputManager(gr_inputManager* _inputManager)
{
	__hook(&gr_inputManager::onMove, _inputManager, &gr_ballManager::onMoveMainBall);
}

void gr_ballManager::unRegisterToInputManager(gr_inputManager* _inputManager)
{
	__unhook(&gr_inputManager::onMove, _inputManager, &gr_ballManager::onMoveMainBall);
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
	mainBall = new gr_ball(glm::vec3(0, 0, 0), glm::vec3(), glm::vec3(BALL_SCALE, BALL_SCALE, BALL_SCALE), "aa.dds", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(gr_util::getRandomRange(0, 1), gr_util::getRandomRange(0, 1), gr_util::getRandomRange(0, 1)));
	balls.push_back(mainBall);
	for (int i = 0; i < _nbItem - 1; ++i)
	{
		gr_ball *_ballToAdd = new gr_ball(glm::vec3(gr_util::getRandomRange(_minPositionX, _maxPositionX), gr_util::getRandomRange(_minPositionY, _maxPositionY), gr_util::getRandomRange(_minPositionZ, _maxPositionZ)), glm::vec3(), glm::vec3(BALL_SCALE, BALL_SCALE, BALL_SCALE), "aa.dds", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(gr_util::getRandomRange(0, 1), gr_util::getRandomRange(0, 1), gr_util::getRandomRange(0, 1)));

		do
		{
			_ballToAdd->setPosition(glm::vec3(gr_util::getRandomRange(_minPositionX, _maxPositionX), gr_util::getRandomRange(_minPositionY, _maxPositionY), gr_util::getRandomRange(_minPositionZ, _maxPositionZ)));
		} while (testCollision(_ballToAdd->getTransform().position) != nullptr);
		balls.push_back(_ballToAdd);
	}

	// register main ball to input
	registerToInputManager(gr_inputManager::getInstance());
}

void gr_ballManager::clear()
{
	balls.clear();
}


void gr_ballManager::deleteAll()
{
	for (int i = 0; i < balls.size(); ++i)
	{
		delete &balls[i];
	}
}

void gr_ballManager::update(float _deltaTime)
{
	gr_ball* _collideBall = nullptr;
	for (int i = 0; i < balls.size(); ++i)
	{
		_collideBall = testCollision(balls[i]->getTransform().position  + balls[i]->getVelocity() * _deltaTime * BALL_SPEED, balls[i]);


		if (_collideBall != nullptr)
		{
			glm::vec3 _director = glm::normalize(_collideBall->getTransform().position - balls[i]->getTransform().position);
			_collideBall->setVelocity((balls[i]->getVelocity() + _director));
		}// test collision todo


		balls[i]->setPosition(balls[i]->getTransform().position + balls[i]->getVelocity() * _deltaTime * BALL_SPEED);

		_collideBall = nullptr;
	}
}

std::vector<gr_ball*> gr_ballManager::getAllBall() const
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
