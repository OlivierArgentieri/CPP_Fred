#include "gr_ball.hpp"

#define  PATH_TO_OBJ "Sphere.obj"

gr_ball::gr_ball(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale,
	const char* _texturePath, const char* _vertexShaderPAth, const char* _fragmentShaderPath, gr_color _color,
	float _radius) : gr_objGameObject(PATH_TO_OBJ, _position, _rotation, _scale, _texturePath, _vertexShaderPAth, _fragmentShaderPath, _color)
{
	radius = _radius;
	SetRadius(radius);
}

float gr_ball::GetRadius() const
{
	return radius;
}

void gr_ball::SetRadius(float _radius)
{
	for (int i = 0; i < vertices.size(); ++i)
	{
		vertices[i] *= _radius;
	}
}
