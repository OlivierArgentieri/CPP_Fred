#pragma once
#include <glm/glm.hpp>

class gr_transform
{

public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	
	gr_transform();
	gr_transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
	gr_transform(const gr_transform& _transform);
};