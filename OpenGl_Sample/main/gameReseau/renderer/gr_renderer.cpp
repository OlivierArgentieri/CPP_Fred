
#include "gr_renderer.hpp"
#include "common/controls.hpp"
#include "main/gameReseau/window/gr_window.hpp"
#include "common/objloader.hpp"
#include <glm/detail/type_mat.hpp>
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

gr_renderer::gr_renderer(const char* _vertexShaderPath, const char* _fragmentShaderPath)
{
	InitGLEW();
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	programID = LoadShaders(_vertexShaderPath, _fragmentShaderPath);

	// Get a handle for our "MVP" unifor
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

void gr_renderer::UseShader()
{
	// Use our shader
	glUseProgram(programID); // todo in game object
	MatrixID = glGetUniformLocation(programID, "MVP");
}


void gr_renderer::ComputeMVPMatrix(GLFWwindow* _window) const
{
	if (!_window) return;
	
	// Compute the MVP matrix from keyboard and mouse input
	computeMatricesFromInputs(_window); // todo 
	glm::mat4 ProjectionMatrix = getProjectionMatrix();
	glm::mat4 ViewMatrix = getViewMatrix();
	glm::mat4 ModelMatrix = glm::mat4(1.0);
	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void gr_renderer::BindTexture(gr_gameObject* _go) // todo
{	
	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _go->GetTexture());
	// Set our "myTextureSampler" sampler to use Texture Unit 0
	glUniform1i(_go->GetTextureID(), 0);
}

void gr_renderer::Draw() const
{
	// Draw the triangle !
	//glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	//glDisableVertexAttribArray(0);
	//glDisableVertexAttribArray(1);
}

void gr_renderer::PollEvent()
{
	glfwPollEvents();
}

void gr_renderer::RenderLoop(gr_window _gr_window)
{
	ClearScreen();
	UseShader();

	for (gr_gameObject* _game_object : gameObjects)
	{
		_game_object->Draw();
		
		ComputeMVPMatrix(_gr_window.GetWindow());
	}
	
	_gr_window.SwapBuffer();
	PollEvent();
}

void gr_renderer::Clean() const
{
	
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
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