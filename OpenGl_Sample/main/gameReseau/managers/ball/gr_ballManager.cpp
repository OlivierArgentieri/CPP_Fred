
#include "main/gameReseau/gameObject/ball/gr_ball.hpp"
#include "gr_ballManager.hpp"


#include <algorithm>
#include <iostream>



#include "main/gameReseau/managers/input/gr_inputManager.hpp"
#include "main/gameReseau/time/gr_time.hpp"

#include "main/gameReseau/util/gr_util.hpp"

#define BALL_SCALE 1
#define BALL_SPEED 5.0f

gr_ballManager* gr_ballManager::instance = nullptr;


void gr_ballManager::onMoveMainBall(glm::vec2 _axisValues)
{
	if (!mainBall || _axisValues == glm::vec2()) return;


	if (!testCollisionBallBall(mainBall->getTransform().position + glm::vec3(_axisValues.x*0.1, 0, _axisValues.y*0.1), mainBall))
		mainBall->addVelocity(glm::vec3(_axisValues.x, 0, _axisValues.y));


}

/// return ball on collide or null
::gr_ball* gr_ballManager::testCollisionBallBall(glm::vec3 _position, gr_ball* _this)
{
	for (int i = 0; i < balls.size(); ++i)
	{
		if (balls[i] != _this && (glm::distance(_position, balls[i]->getTransform().position) < balls[i]->getTransform().scale.x*2))
			return balls[i];
	}

	return nullptr; // ok
}

/// return plane on collide or null
gr_ball* gr_ballManager::testCollisionBallPlane(glm::vec3 _position, gr_ball* _this)
{
	return nullptr;
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

void gr_ballManager::makeSpawn(unsigned _nbItem, float _minPositionX, float _maxPositionX, float _minPositionY, float _maxPositionY, float _minPositionZ, float _maxPositionZ, std::vector<gr_gameObject*> _obstacles = std::vector<gr_gameObject*>())
{
	mainBall = new gr_ball(glm::vec3(0, 0, 0), glm::vec3(), glm::vec3(BALL_SCALE, BALL_SCALE, BALL_SCALE), gr_bounds(glm::vec3(1,1,1), glm::vec3()),  "aa.dds", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(gr_util::getRandomRange(0, 1), gr_util::getRandomRange(0, 1), gr_util::getRandomRange(0, 1)), _obstacles);
	balls.push_back(mainBall);
	for (int i = 0; i < _nbItem - 1; ++i)
	{
		gr_ball *_ballToAdd = new gr_ball(glm::vec3(gr_util::getRandomRange(_minPositionX, _maxPositionX), gr_util::getRandomRange(_minPositionY, _maxPositionY), gr_util::getRandomRange(_minPositionZ, _maxPositionZ)), glm::vec3(), glm::vec3(BALL_SCALE, BALL_SCALE, BALL_SCALE), gr_bounds(), "aa.dds", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(gr_util::getRandomRange(0, 1), gr_util::getRandomRange(0, 1), gr_util::getRandomRange(0, 1)), _obstacles);

		do
		{
			_ballToAdd->setPosition(glm::vec3(gr_util::getRandomRange(_minPositionX, _maxPositionX), gr_util::getRandomRange(_minPositionY, _maxPositionY), gr_util::getRandomRange(_minPositionZ, _maxPositionZ)));
		} while (testCollisionBallBall(_ballToAdd->getTransform().position) != nullptr);
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
		delete balls[i];
	}
}

// update method of gamObject (behaviour for gamePlay)
void gr_ballManager::update(float _deltaTime)
{
	collisionToEachOther(_deltaTime);

	for (int i = 0; i < balls.size(); ++i)
	{
		
		for (int j = 0; j < balls[i]->getObstacles().size(); ++j)
		{
			if(CubeSphereCollision(*balls[i]->getObstacles()[j], balls[i]))
			{
				std::cout << "collide" << "\n";
				glm::vec3 _director = glm::normalize(balls[i]->getObstacles()[j]->getTransform().position - balls[i]->getTransform().position);

				//balls[i]->getObstacles()[j]->getNormals();
				//balls[i]->setVelocity(-balls[i]->getVelocity());
				balls[i]->setVelocity(glm::reflect(balls[i]->getVelocity(), balls[i]->getObstacles()[j]->getNormals()[0]));
			}
		}
	}

	for (int i = 0; i < balls.size(); ++i)
	{
		// move
		balls[i]->setPosition(balls[i]->getTransform().position + balls[i]->getVelocity() *  _deltaTime * BALL_SPEED);
	}

}

// - start collision
void gr_ballManager::collisionToEachOther(float _deltaTime)
{
	gr_ball* _collideBall = nullptr;
	for (int i = 0; i < balls.size(); ++i)
	{
		_collideBall = testCollisionBallBall(balls[i]->getTransform().position + balls[i]->getVelocity() * _deltaTime * BALL_SPEED, balls[i]);


		if (_collideBall != nullptr)
		{
			glm::vec3 _director = glm::normalize(_collideBall->getTransform().position - balls[i]->getTransform().position);
			_collideBall->setVelocity((balls[i]->getVelocity() + _director));
		}// test collision todo refactor


		
		_collideBall = nullptr;
	}
}

bool gr_ballManager::CubeSphereCollision(gr_gameObject _cube, gr_ball* _ball)
{
	glm::vec3 _d = _ball->getTransform().position - _cube.getTransform().position;
	
	float _x = gr_util::clamp(_d.x, -_cube.getTransform().scale.x / 2, _cube.getTransform().scale.x / 2);
	float _y = gr_util::clamp(_d.y, -_cube.getTransform().scale.y / 2, _cube.getTransform().scale.y / 2);
	float _z = gr_util::clamp(_d.z, -_cube.getTransform().scale.z / 2, _cube.getTransform().scale.z / 2);
	
	glm::vec3 _clampedVector = glm::vec3(_x, _y, _z);
	glm::vec3 _closest = _cube.getTransform().position + _clampedVector;
	_d = _closest - _ball->getTransform().position;

	return glm::length(_d) <= _ball->getTransform().scale.x;
}

void gr_ballManager::clean()
{
	deleteAll();
	clear();
}

std::vector<gr_ball*> gr_ballManager::getAllBall() const
{
	return balls;
}
