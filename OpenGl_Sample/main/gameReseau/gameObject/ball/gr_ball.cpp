#include "gr_ball.hpp"

#define  PATH_TO_OBJ "Sphere.obj"

gr_ball::gr_ball(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, const char* _texturePath, const char* _vertexShaderPAth, const char* _fragmentShaderPath, gr_color _color) : gr_objGameObject(
		PATH_TO_OBJ, _position, _rotation, _scale, _texturePath, _vertexShaderPAth, _fragmentShaderPath, _color)
{
	gr_gameObject::SetScale(_scale);
}

gr_ball::gr_ball(const gr_ball& _ball) : gr_objGameObject(_ball)
{
	vertices = _ball.vertices;
	uvs = _ball.uvs;
	normals = _ball.normals;

	fragmentShaderPath = _ball.fragmentShaderPath;
	vertexShaderPath = _ball.vertexShaderPath;

	
	SetPosition(_ball.transform.position);
	SetColorShader(_ball.Color);
	
	gr_gameObject::SetScale(_ball.transform.scale);
}

void gr_ball::addVelocity(glm::vec3 _velocity)
{
	velocity += _velocity;
}

glm::vec3 gr_ball::getVelocity() const
{
	return velocity;
}

void gr_ball::update()
{
	if(velocity != glm::vec3())
	{
	//	SetPosition(transform.position + velocity); // todo

		// decrement velocity
		velocity *= 0.80f; // frottement
	}
}

