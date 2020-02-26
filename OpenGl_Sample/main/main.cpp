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
#include "gameReseau/gameObject/objGameObject/gr_objGameObject.hpp"
#include "gameReseau/gameObject/gameBoard/gr_gameBoard.hpp"
class gr_gameObject;
using namespace glm;

#include <common/objloader.hpp>


int main( void )
{

	gr_window grWindow = gr_window(1024, 768,"Tutorial 07 - Model Loading", gr_color(0.0f, 0.0f, .1f, 0));

	grWindow.InitWindow();
	gr_renderer grRenderer = gr_renderer("TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader");

	
	gr_objGameObject _cube = gr_objGameObject("cube.obj");
	gr_gameBoard _board = gr_gameBoard();


	grRenderer.AddGameObject(&_cube);
	grRenderer.AddGameObject(&_board);
	
	do
	{
		_cube.MoveRight(0.1, 1);

	//	grRenderer.ClearVerticesAndUV();

//		grRenderer.AddVertices(_cube.getVertices());
	//	grRenderer.AddUV(_cube.getUvs());
		
//		grRenderer.AddVertices(vertices);
		
	//	grRenderer.AddUV(uvs);

		
		grRenderer.RenderLoop(grWindow);


	}
	while (glfwGetKey(grWindow.GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(grWindow.GetWindow()) == 0);

	grRenderer.Clean();
	
	return 0;
}