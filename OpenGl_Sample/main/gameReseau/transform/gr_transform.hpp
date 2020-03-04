#pragma once
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class gr_transform
{
	
private:
	glm::mat4 ModelMatrix;
	
public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	
	gr_transform();
	gr_transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
	gr_transform(const gr_transform& _transform);

	void SetPosition(glm::vec3 _position);
	void SetScale(glm::vec3 _scale);

	glm::mat4 GetMVP() const;
};