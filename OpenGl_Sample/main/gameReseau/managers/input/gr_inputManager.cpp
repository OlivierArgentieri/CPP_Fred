#include "gr_inputManager.hpp"

#include <glm/detail/type_vec2.hpp>


#include "GLFW/glfw3.h"
#include "main/gameReseau/window/gr_window.hpp"

gr_inputManager* gr_inputManager::instance = nullptr;

gr_inputManager::gr_inputManager() = default;

gr_inputManager* gr_inputManager::getInstance()
{
 	if (instance == nullptr)
		instance = new gr_inputManager();
	return instance;
}

void gr_inputManager::update(gr_window _window)
{
	glm::vec2 _axis = glm::vec2();


	// Strafe up
	if (glfwGetKey(_window.getWindow(), GLFW_KEY_W) == GLFW_PRESS) {
		_axis += glm::vec2(0, -1);
	}
	
	// Strafe down
	if (glfwGetKey(_window.getWindow(), GLFW_KEY_S) == GLFW_PRESS) {
		_axis += glm::vec2(0, 1);
	}
	
	// Strafe right
	if (glfwGetKey(_window.getWindow(), GLFW_KEY_D) == GLFW_PRESS) {
		_axis += glm::vec2(1,0);
	}

	// Strafe left
	if (glfwGetKey(_window.getWindow(), GLFW_KEY_A) == GLFW_PRESS) {
		_axis += glm::vec2(-1, 0);
	}

	__raise onMove(_axis);
}