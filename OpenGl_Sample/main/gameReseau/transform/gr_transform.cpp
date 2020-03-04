#include "gr_transform.hpp"

#include <glm/gtc/matrix_transform.inl>
#include "common/controls.hpp"


gr_transform::gr_transform() : gr_transform(glm::vec3(), glm::vec3(), glm::vec3())
{
	//ModelMatrix = glm::mat4(1);
}

gr_transform::gr_transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale)
{
	position = _position;
	rotation = _rotation;
	scale = _scale;
	//ModelMatrix = glm::mat4(1);
}

gr_transform::gr_transform(const gr_transform& _transform) : gr_transform(_transform.position, _transform.rotation, _transform.scale)
{
	//ModelMatrix = glm::mat4(1);
	ModelMatrix = _transform.ModelMatrix;
}

void gr_transform::SetPosition(glm::vec3 _position)
{
	position = _position;
	ModelMatrix = glm::mat4(1);
	ModelMatrix = glm::translate(ModelMatrix, _position);
}

void gr_transform::translate(glm::vec3 _position)
{
	position += _position;
	ModelMatrix = glm::translate(ModelMatrix, _position);
}


void gr_transform::SetScale(glm::vec3 _scale)
{
	scale = _scale;
}

glm::mat4 gr_transform::GetMVP() const
{
	return  getProjectionMatrix() * getViewMatrix() * ModelMatrix;
}
