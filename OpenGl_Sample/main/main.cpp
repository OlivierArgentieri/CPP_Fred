// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>

// Include GLEW
#include <GL/glew.h>


// Include GLFW
#include <GLFW/glfw3.h>
#include "gameReseau/window/gr_window.hpp"
#include "gameReseau/renderer/gr_renderer.hpp"
//GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <random>


#include "gameReseau/gameObject/ball/gr_ball.hpp"
#include "gameReseau/gameObject/objGameObject/gr_objGameObject.hpp"
#include "gameReseau/gameObject/gameBoard/gr_gameBoard.hpp"
#include "gameReseau/managers/ball/gr_ballManager.hpp"
#include "gameReseau/managers/input/gr_inputManager.hpp"
#include "gameReseau/player/gr_player.hpp"
#include "gameReseau/time/gr_time.hpp"

class gr_gameObject;
using namespace glm;

#include <common/objloader.hpp>


int main( void )
{
	gr_window grWindow = gr_window(1024, 768,"Tutorial 07 - Model Loading", gr_color(0.0f, 0.0f, .1f, 0));

	grWindow.initWindow();
	gr_renderer grRenderer = gr_renderer();

	
	gr_objGameObject _cube = gr_objGameObject("Sphere.obj", "", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(1,0,0));
	gr_ball _ball = gr_ball(vec3(10,0,0), vec3(), vec3(1,1,1), gr_bounds(vec3(1, 1, 1), glm::vec3()), "aaa.DDS", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(0,1,0));
	gr_ball _cube2 = gr_ball(glm::vec3(0, 0, 0), glm::vec3(1,1,1) , glm::vec3(0, 0, 0), gr_bounds(), "aaa.DDS", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(1, 1, 1));
	gr_gameBoard _board = gr_gameBoard();

	grRenderer.addGameObject(&_board);

	
	gr_ballManager::getInstance()->makeSpawn(1,-10,10,0,0,-10,10, _board.getElementComposed());
	auto _test = gr_ballManager::getInstance()->getAllBall();

	// init sphere list 
	for (int i = 0; i < _test.size(); ++i)
	{
		grRenderer.addGameObject(_test[i]);
	}


	//game Loop
	do
	{
		gr_inputManager::getInstance()->update(grWindow);
		gr_ballManager::getInstance()->update(gr_time::getDeltaTime());
		grRenderer.renderLoop(grWindow);
	}
	while (glfwGetKey(grWindow.getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(grWindow.getWindow()) == 0);

	gr_ballManager::getInstance()->clean();
	grRenderer.clean();
	
	return 0;
}