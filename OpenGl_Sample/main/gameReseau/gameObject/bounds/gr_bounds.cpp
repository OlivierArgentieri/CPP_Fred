#include "gr_bounds.hpp"

gr_bounds::gr_bounds() : gr_bounds(glm::vec3(),glm::vec3())
{
}

gr_bounds::gr_bounds(glm::vec3 _size, glm::vec3 _center)
{
	size = _size;
	center = _center;
}

gr_bounds::gr_bounds(const gr_bounds& _ref)
{
	size = _ref.size;
	center = _ref.center;
}

glm::vec3 gr_bounds::getSize() const
{
	return size;
}

glm::vec3 gr_bounds::getCenter() const
{
	return center;
}
