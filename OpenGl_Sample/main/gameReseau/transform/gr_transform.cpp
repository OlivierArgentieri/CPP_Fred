#include "gr_transform.hpp"


gr_transform::gr_transform() : gr_transform(glm::vec3(), glm::vec3(), glm::vec3())
{
}

gr_transform::gr_transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale)
{
	position = _position;
	rotation = _rotation;
	scale = _scale;
}

gr_transform::gr_transform(const gr_transform& _transform) : gr_transform(_transform.position, _transform.rotation, _transform.scale)
{
}