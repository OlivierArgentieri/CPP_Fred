#include "gr_ball.hpp"

#define  PATH_TO_OBJ "Sphere.obj"

gr_ball::gr_ball(const char* _texturePath, const char* _vertexShaderPAth, const char* _fragmentShaderPath, const gr_color _color, float _radius) : gr_objGameObject(
	PATH_TO_OBJ, _texturePath, _vertexShaderPAth, _fragmentShaderPath, _color)
{
	radius = _radius;
}

float gr_ball::GetRadius() const
{
	return radius;
}