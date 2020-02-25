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
	
	// Read our .obj file*/
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // Won't be used at the moment.
	
	

	/*
	for (auto i = vertices.begin(); i < vertices.end(); ++i)
		*i = vec3(i->x * 5, i->y * 5, i->z * 5);
	*/


	// plane
	vertices.push_back(glm::vec3(-50, 0, -50));
	vertices.push_back(glm::vec3(-50, 0, 50));
	vertices.push_back(glm::vec3(50, 0, 50));

	vertices.push_back(glm::vec3(50, 0, 50));
	vertices.push_back(glm::vec3(50, 0, -50));
	vertices.push_back(glm::vec3(-50, 0, -50));
	// end plane


	// CG 
	vertices.push_back(glm::vec3(-50, 10, 50));
	vertices.push_back(glm::vec3(-50, 0, 50));
	vertices.push_back(glm::vec3(-50, 0, -50));
	
	vertices.push_back(glm::vec3(-50, 0, -50));
	vertices.push_back(glm::vec3(-50, 10, -50));
	vertices.push_back(glm::vec3(-50, 10, 50));
	//

	
	// CB 
	vertices.push_back(glm::vec3(50, 10, 50));
	vertices.push_back(glm::vec3(50, 0, 50));
	vertices.push_back(glm::vec3(-50, 0, 50));
	
	vertices.push_back(glm::vec3(-50, 0, 50));
	vertices.push_back(glm::vec3(-50, 10, 50));
	vertices.push_back(glm::vec3(50, 10, 50));
	//


	
	// CD
	vertices.push_back(glm::vec3(50, 10, -50));
	vertices.push_back(glm::vec3(50, 0, -50));
	vertices.push_back(glm::vec3(50, 0, 50));
	
	vertices.push_back(glm::vec3(50, 0, 50));
	vertices.push_back(glm::vec3(50, 10, 50));
	vertices.push_back(glm::vec3(50, 10, -50));
	//
	
	
	// CH
	vertices.push_back(glm::vec3(50, 10, -50));
	vertices.push_back(glm::vec3(50, 0, -50));
	vertices.push_back(glm::vec3(50, 0, 50));

	vertices.push_back(glm::vec3(50, 0, 50));
	vertices.push_back(glm::vec3(50, 10, 50));
	vertices.push_back(glm::vec3(50, 10, -50));
	//


	// CT 
	vertices.push_back(glm::vec3(-50, 0, -50));
	vertices.push_back(glm::vec3(50, 0, -50));
	vertices.push_back(glm::vec3(50, 10, -50));
	vertices.push_back(glm::vec3(50, 10, -50));
	vertices.push_back(glm::vec3(-50, 10, -50));
	vertices.push_back(glm::vec3(-50, 0, -50));
	//
	
	// CT - reverse
	vertices.push_back(glm::vec3(50, 10, -50));
	vertices.push_back(glm::vec3(50, 0, -50));
	vertices.push_back(glm::vec3(-50, 0, -50));

	vertices.push_back(glm::vec3(50, 10, -50));
	vertices.push_back(glm::vec3(-50, 0, -50));
	vertices.push_back(glm::vec3(-50, 10, -50));
	//

	
	/*
	vertices.push_back(glm::vec3(0, 0, 0));
	vertices.push_back(glm::vec3(0, 0, 100));
	vertices.push_back(glm::vec3(100, 0, 100));
	
	vertices.push_back(glm::vec3(100, 0, 100));
	vertices.push_back(glm::vec3(100, 0, 0));
	vertices.push_back(glm::vec3(0, 0, 0));
	*/
	
	/*
	vertices.push_back(glm::vec3(0, 0, 0));
	vertices.push_back(glm::vec3(100, 0, 0));
	vertices.push_back(glm::vec3(0, 100, 0));

	vertices.push_back(glm::vec3(100, 0, 0));
	vertices.push_back(glm::vec3(100, 100, 0));
	vertices.push_back(glm::vec3(0, 100, 0));
	*/


	/**/
	uvs.push_back(glm::vec2(0, 0));
	uvs.push_back(glm::vec2(0, 1));
	uvs.push_back(glm::vec2(1, 1));
	
	uvs.push_back(glm::vec2(1, 1));
	uvs.push_back(glm::vec2(1, 0));
	uvs.push_back(glm::vec2(0, 0));

	
	grRenderer.AddVertices(vertices);
	grRenderer.AddUV(uvs);


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