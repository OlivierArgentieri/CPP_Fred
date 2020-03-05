#pragma once
#include <glm/detail/type_vec2.hpp>

#include "main/gameReseau/window/gr_window.hpp"

class gr_inputManager
{
private:
	static gr_inputManager* instance;


	
public:
	__event void onMove(glm::vec2 _axisPosition);
	gr_inputManager();

	static gr_inputManager* getInstance();

	void update(gr_window _window, float _deltaTime);
};
