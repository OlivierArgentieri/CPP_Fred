#include <glm/detail/type_vec3.hpp>
#include <vector>
#include <glm/glm.hpp>

#include <GL/glew.h>
#include <cstdio>
#include "GLFW/glfw3.h"
#include "common/texture.hpp"
#include "common/shader.hpp"
#include "main/gameReseau/window/gr_window.hpp"

class gr_renderer
{
private :
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	// buffers
	GLuint vertexBuffer;
	GLuint uvBuffer;
	
	GLuint VertexArrayID;
	GLuint programID;
	GLuint MatrixID;
	GLuint Texture;
	GLuint TextureID;

	static void InitGLEW();
	void LoadVBO();
	void LoadUVBuffer();
	void ClearScreen();
	void UseShader() const;
	void ComputeMVPMatrix(GLFWwindow* _window) const;
	void BindTexture();
	void VerticesBuffer();
	void UvBuffer();
	void Draw() const;
	static void PollEvent();
	static void Close();

public:
	gr_renderer(const char* _vertexShaderPath, const char* _fragmentShaderPath);

	void AddVertices(std::vector<glm::vec3> _vertices);
	void AddUV(std::vector<glm::vec2> _uvs);

	void RenderLoop(gr_window _gr_window);
	void Clean() const;
};
