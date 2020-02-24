#include <glm/detail/type_vec3.hpp>
#include <vector>
#include <glm/glm.hpp>

#include <GL/glew.h>
#include <cstdio>
#include "GLFW/glfw3.h"
#include "common/texture.hpp"
#include "common/shader.hpp"

class gr_renderer
{
private :
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	
	void InitGLEW();
	void InitVBO();
	void InitUVBuffer();
	
public:
	gr_renderer(const char* _vertexShaderPath, const char* _fragmentShaderPath);
	void InitRenderer();

	void AddVertices(std::vector<glm::vec3> _vertices);
	void AddVertices(std::vector<glm::vec2> _uvs);
};
