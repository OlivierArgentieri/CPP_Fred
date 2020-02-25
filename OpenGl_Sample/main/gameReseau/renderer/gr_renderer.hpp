#include <glm/detail/type_vec3.hpp>
#include <vector>
#include <glm/glm.hpp>

#include <GL/glew.h>
#include <cstdio>
#include "GLFW/glfw3.h"
#include "common/texture.hpp"
#include "common/shader.hpp"
#include "main/gameReseau/window/gr_window.hpp"
#include "main/gameReseau/gameObject/gr_gameObject.hpp"

class gr_renderer
{
private :
	std::vector<gr_gameObject*> gameObjects;
	
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // not use todo

	// buffers
	GLuint vertexBuffer;
	GLuint uvBuffer;
	
	GLuint VertexArrayID;
	GLuint programID;
	GLuint MatrixID;
	GLuint Texture;
	GLuint TextureID;

	static void InitGLEW();
	void ClearScreen();
	void UseShader() const;
	void ComputeMVPMatrix(GLFWwindow* _window) const;
	void BindTexture();
	void Draw() const;
	static void PollEvent();
	static void Close();

public:
	gr_renderer(const char* _vertexShaderPath, const char* _fragmentShaderPath);

	void AddVertices(std::vector<glm::vec3> _vertices);
	void AddUV(std::vector<glm::vec2> _uvs);

	void RenderLoop(gr_window _gr_window);
	void Clean() const;
	void ClearVerticesAndUV();
	void AddGameObject(gr_gameObject *_go);

};
