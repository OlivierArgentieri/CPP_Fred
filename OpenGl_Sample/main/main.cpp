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
class gr_gameObject;
using namespace glm;

#include <common/objloader.hpp>


int main( void )
{
	gr_window grWindow = gr_window(1024, 768,"Tutorial 07 - Model Loading", gr_color(0.0f, 0.0f, .1f, 0));

	grWindow.InitWindow();
	gr_renderer grRenderer = gr_renderer();

	
	gr_objGameObject _cube = gr_objGameObject("Sphere.obj", "", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(1,0,0));
	gr_ball _cube2 = gr_ball(glm::vec3(20, 0, 0), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0), "aa.DDS", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(1, 1, 1), 10);
	gr_gameBoard _board = gr_gameBoard();
		

	grRenderer.AddGameObject(&_cube);
	grRenderer.AddGameObject(&_cube2);
	grRenderer.AddGameObject(&_board);

	/*
	std::random_device dev;
	std::mt19937 rng(dev());
	
	std::uniform_real_distribution<float> dist(-12, 2);

	std::cout << dist(rng) << std::endl;*/
	//_cube2.getTransform().setPosition(glm::vec3(0, 1, 1));

	do
	{
		_cube2.setPosition(glm::vec3(0.1f, 0, 0));

		grRenderer.RenderLoop(grWindow);
	}
	while (glfwGetKey(grWindow.GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(grWindow.GetWindow()) == 0);

	grRenderer.Clean();
	
	return 0;
}