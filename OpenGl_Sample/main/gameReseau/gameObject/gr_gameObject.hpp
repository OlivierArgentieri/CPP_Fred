#pragma once
#include <vector>
#include <gl/glew.h>
#include <glm/glm.hpp>
#include "main/gameReseau/transform/gr_transform.hpp"

class gr_gameObject
{
protected:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // not used


	GLuint Texture; // todo

	gr_transform transform;
	
	void LoadTexture();
public:

	gr_gameObject(const char* _pathObj);

	std::vector<glm::vec3> getVertices() const;
	std::vector<glm::vec2> getUvs() const;
	std::vector<glm::vec3> getNormals() const;
};
