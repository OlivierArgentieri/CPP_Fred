#pragma once
#include <glm/detail/type_vec3.hpp>
#include <vector>

#include "main/gameReseau/managers/input/gr_inputManager.hpp"

class gr_ball;

[event_receiver(native)]
class gr_ballManager
{
private:
	static gr_ballManager* instance;
	
	void OnMoveMainBall(glm::vec2 _axisValues);

	std::vector<gr_ball*> balls;
	bool TestCollision(glm::vec3 _position, gr_ball* _this = nullptr);

	// event register/unregister
	void RegisterToInputManager(gr_inputManager* _inputManager);
	void UnRegisterToInputManager(gr_inputManager* _inputManager);
	~gr_ballManager();

	gr_ball* mainBall;
public:
	
	static gr_ballManager* getInstance();
	void addBalls(gr_ball* _ball);
	void makeSpawn(unsigned _nbItem, float _minPositionX, float _maxPositionX, float _minPositionY, float _maxPositionY, float _minPositionZ, float _maxPositionZ);
	void Clear();
	void DeleteAll();
	void Update();
	std::vector<gr_ball*> GetAllBall() const;
};
