
#include "gr_renderer.hpp"


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

void gr_renderer::InitVBO()
{
	// Load it into a VBO
	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
}

void gr_renderer::InitUVBuffer()
{
	GLuint uvbuffer;
	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
}


gr_renderer::gr_renderer(const char* _vertexShaderPath, const char* _fragmentShaderPath)
{
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders(_vertexShaderPath, _fragmentShaderPath);

	// Get a handle for our "MVP" uniform
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	// Load the texture
	GLuint Texture = loadDDS("uvmap.DDS");

	// Get a handle for our "myTextureSampler" uniform
	GLuint TextureID = glGetUniformLocation(programID, "myTextureSampler");

}

void gr_renderer::AddVertices(std::vector<glm::vec3> _vertices)
{
	for (glm::vec3 value : _vertices)
	{
		vertices.push_back(value);
	}
}

void gr_renderer::AddVertices(std::vector<glm::vec2> _uvs)
{
	for (glm::vec2 value : _uvs)
	{
		uvs.push_back(value);
	}
}
