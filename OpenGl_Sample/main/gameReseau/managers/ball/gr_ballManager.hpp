#pragma once
#include <glm/detail/type_vec3.hpp>
#include <vector>

#include "main/gameReseau/managers/input/gr_inputManager.hpp"

class gr_ball;

class gr_ballManager
{
private:
	static gr_ballManager* instance;

	gr_ball* mainBall;

	void onMoveMainBall(glm::vec2 _axisValues);

	std::vector<gr_ball*> balls;

	//collisions
	gr_ball* testCollisionBallBall(glm::vec3 _position, gr_ball* _this = nullptr);
	gr_ball* testCollisionBallPlane(glm::vec3 _position, gr_ball* _this = nullptr);
	void collisionToEachOther(float _deltaTime);
	void CubeSphereCollision(gr_gameObject _cube, gr_ball _ball);


	// event methods
	void registerToInputManager(gr_inputManager* _inputManager);
	void unRegisterToInputManager(gr_inputManager* _inputManager);
	
	~gr_ballManager();


	void clear();
	void deleteAll();
	
public:
	
	static gr_ballManager* getInstance();
	void addBalls(gr_ball* _ball);
	void makeSpawn(unsigned _nbItem, float _minPositionX, float _maxPositionX, float _minPositionY, float _maxPositionY, float _minPositionZ, float _maxPositionZ, std::vector<gr_gameObject> _obstacles);
	
	void update(float _deltaTime);
	void clean();
	std::vector<gr_ball*> getAllBall() const;
};
