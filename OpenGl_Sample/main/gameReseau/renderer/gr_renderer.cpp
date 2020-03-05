
#include "gr_renderer.hpp"
#include "common/controls.hpp"
#include "main/gameReseau/window/gr_window.hpp"
#include "common/objloader.hpp"
#include <glm/detail/type_mat.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "main/gameReseau/time/gr_time.hpp"


void gr_renderer::initGLEW()
{
	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
	}
}

gr_renderer::gr_renderer()
{
	initGLEW();
	glGenVertexArrays(1, &vertexArrayID);
	glBindVertexArray(vertexArrayID);
}

void gr_renderer::addGameObject(gr_gameObject *_go)
{
	gameObjects.push_back(_go);
}

void gr_renderer::addVertices(std::vector<glm::vec3> _vertices)
{
	for (glm::vec3 vertex : _vertices)
	{
		vertices.push_back(vertex);
	}
}

void gr_renderer::addUV(std::vector<glm::vec2> _uvs)
{
	for (glm::vec2 value : _uvs)
	{
		uvs.push_back(value);
	}
}

void gr_renderer::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void gr_renderer::clearVerticesAndUV()
{
	vertices.clear();
	uvs.clear();
}

void gr_renderer::drawEachObject(gr_window _gr_window) const
{
	for (gr_gameObject* _game_object : gameObjects)
	{
		_game_object->draw(&_gr_window);
	}
}

void gr_renderer::pollEvent()
{
	glfwPollEvents();
}

void gr_renderer::renderLoop(gr_window _gr_window) const
{
	// delta time
	gr_time::beginFrame();
	clearScreen();
	drawEachObject(_gr_window);
	
	_gr_window.swapBuffer();
	pollEvent();

	gr_time::endFrame();
}


void gr_renderer::clean() const
{
	for (gr_gameObject* _game_object : gameObjects)
	{
		_game_object->clean();
	}
	close();
}

void gr_renderer::cleanGameObject() const
{
	for (gr_gameObject* _game_object : gameObjects)
	{
		if (!_game_object) continue;
		_game_object->clean();
	}
}

void gr_renderer::close()
{
	glfwTerminate();
}