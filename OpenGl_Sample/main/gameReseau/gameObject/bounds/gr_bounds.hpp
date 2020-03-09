#pragma once
#include <glm/glm.hpp>

class gr_bounds
{
private:
	glm::vec3 size;
	glm::vec3 center;

public:
	gr_bounds();
	gr_bounds(glm::vec3 _size, glm::vec3 _center);
	gr_bounds(const gr_bounds& _ref);
	
	glm::vec3 getSize() const;
	glm::vec3 getCenter() const;
};
