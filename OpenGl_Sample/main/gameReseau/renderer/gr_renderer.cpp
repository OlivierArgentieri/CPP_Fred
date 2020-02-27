
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

	// Get a handle for our "MVP" uniform
	MatrixID = glGetUniformLocation(programID, "MVP");
		
	// Load the texture
	//Texture = loadDDS("uvmap.DDS"); // todo 
	//Texture = loadDDS("UVChecker.dds"); // todo 
	Texture = loadDDS("aa.dds"); // todo 

	// Get a handle for our "myTextureSampler" uniform
	TextureID = glGetUniformLocation(programID, "myTextureSampler"); // todo

}

void gr_renderer::AddGameObject(gr_gameObject *_go)
{
	gameObjects.push_back(_go);
}

void gr_renderer::AddVertices(std::vector<glm::vec3> _vertices)
{
	//vertices.clear();
	for (glm::vec3 vertex : _vertices)
	{
		vertices.push_back(vertex);
	}
	
	//LoadVBO();
}

void gr_renderer::AddUV(std::vector<glm::vec2> _uvs)
{
	for (glm::vec2 value : _uvs)
	{
		uvs.push_back(value);
	}
	//LoadUVBuffer();
}

void gr_renderer::ClearScreen()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void gr_renderer::ClearVerticesAndUV()
{
	vertices.clear();
	uvs.clear();
}

void gr_renderer::UseShader() const
{
	// Use our shader
	glUseProgram(programID); // todo
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

void gr_renderer::BindTexture() // todo
{/**/
	
	
	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture);
	// Set our "myTextureSampler" sampler to use Texture Unit 0
	glUniform1i(TextureID, 0);
}

void gr_renderer::Draw() const
{
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

void gr_renderer::PollEvent()
{
	glfwPollEvents();
}

void gr_renderer::RenderLoop(gr_window _gr_window)
{
	ClearScreen();
	UseShader();
	
	ComputeMVPMatrix(_gr_window.GetWindow());
	BindTexture();
	
	for (gr_gameObject* _game_object : gameObjects)
	{
		_game_object->Draw();
	}
	
	_gr_window.SwapBuffer();
	PollEvent();
}

void gr_renderer::Clean() const
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &uvBuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
	Close();
}

void gr_renderer::Close()
{
	glfwTerminate();
}