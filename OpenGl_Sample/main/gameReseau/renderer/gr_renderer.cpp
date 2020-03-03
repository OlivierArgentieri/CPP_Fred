
#include "gr_renderer.hpp"
#include "common/controls.hpp"
#include "main/gameReseau/window/gr_window.hpp"
#include "common/objloader.hpp"
#include <glm/detail/type_mat.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>


void gr_renderer::InitGLEW()
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
	InitGLEW();
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	//programID = LoadShaders(_vertexShaderPath, _fragmentShaderPath);

	
	// Get a handle for our "MVP" uniform
}

void gr_renderer::AddGameObject(gr_gameObject *_go)
{
	gameObjects.push_back(_go);
}

void gr_renderer::AddVertices(std::vector<glm::vec3> _vertices)
{
	for (glm::vec3 vertex : _vertices)
	{
		vertices.push_back(vertex);
	}
}

void gr_renderer::AddUV(std::vector<glm::vec2> _uvs)
{
	for (glm::vec2 value : _uvs)
	{
		uvs.push_back(value);
	}
}

void gr_renderer::ClearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void gr_renderer::ClearVerticesAndUV()
{
	vertices.clear();
	uvs.clear();
}

void gr_renderer::DrawEachObject(gr_window _gr_window) const
{
	for (gr_gameObject* _game_object : gameObjects)
	{
		_game_object->Draw(&_gr_window);
	}
}

void gr_renderer::PollEvent()
{
	glfwPollEvents();
}

void gr_renderer::RenderLoop(gr_window _gr_window) const
{
	ClearScreen();
	DrawEachObject(_gr_window);
	
	_gr_window.SwapBuffer();
	PollEvent();
}


void gr_renderer::Clean() const
{
	for (gr_gameObject* _game_object : gameObjects)
	{
		_game_object->Clean();
	}
	Close();
}

void gr_renderer::CleanGameObject() const
{
	for (gr_gameObject* _game_object : gameObjects)
	{
		if (!_game_object) continue;
		_game_object->Clean();
	}
}

void gr_renderer::Close()
{
	glfwTerminate();
}