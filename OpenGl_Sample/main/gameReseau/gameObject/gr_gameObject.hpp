#pragma once
#include <vector>
#include <gl/glew.h>
#include <glm/glm.hpp>

class gr_gameObject
{
protected:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // not used


	GLuint Texture;

	void LoadTexture();
public:


	std::vector<glm::vec3> getVertices() const;
	std::vector<glm::vec2> getUvs() const;
	std::vector<glm::vec3> getNormals() const;
};
