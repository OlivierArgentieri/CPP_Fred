#pragma once
#include "main/gameReseau/gameObject/ball/gr_ball.hpp"

class gr_inputManager;

[event_receiver(native)]
class gr_player
{
private:
	gr_ball *ball;

	void OnMove(glm::vec2 _axisValues);

	void RegisterToInputManager(gr_inputManager *_inputManager);
	void UnRegisterToInputManager(gr_inputManager *_inputManager);
public:
	gr_player(gr_ball* _ball);
	
};
