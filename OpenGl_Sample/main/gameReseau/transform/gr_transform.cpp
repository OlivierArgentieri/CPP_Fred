#include "gr_transform.hpp"

#include <glm/gtc/matrix_transform.inl>
#include "common/controls.hpp"


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
	modelMatrix = _transform.modelMatrix;
}

void gr_transform::setPosition(glm::vec3 _position)
{
	position = _position;
	modelMatrix = glm::mat4(1);
	modelMatrix = glm::translate(modelMatrix, _position);
}

void gr_transform::translate(glm::vec3 _position)
{
	position += _position;
	modelMatrix = glm::translate(modelMatrix, _position);
}


void gr_transform::setScale(glm::vec3 _scale)
{
	scale = _scale;
}

glm::mat4 gr_transform::getMVP() const
{
	return  getProjectionMatrix() * getViewMatrix() * modelMatrix;
}
