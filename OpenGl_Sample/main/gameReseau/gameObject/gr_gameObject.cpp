#include "gr_gameObject.hpp"
#include "main/gameReseau/renderer/gr_renderer.hpp"
#include "common/objloader.hpp"


void gr_gameObject::LoadTexture()
{
	// Load the texture
	//Texture = loadDDS("uvmap.DDS"); // todo 
	Texture = loadDDS("UVChecker.dds"); // todo 

}

gr_gameObject::gr_gameObject() : gr_gameObject(glm::vec3(), glm::vec3(), glm::vec3())
{
	
}

gr_gameObject::gr_gameObject(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale)
{
	transform = gr_transform(_position, _rotation, _scale);
}

gr_gameObject::gr_gameObject(const gr_gameObject& _gameObject)
{
	transform = gr_transform(_gameObject.transform);
}


std::vector<glm::vec3> gr_gameObject::getVertices() const
{
	return vertices;
}

std::vector<glm::vec2> gr_gameObject::getUvs() const
{
	return uvs;
}

std::vector<glm::vec3> gr_gameObject::getNormals() const
{
	return normals;
}

void gr_gameObject::MoveRight(float _speed, float _deltaTime)
{
	for (glm::vec3 &vertex : vertices)
	{
		vertex.x += _speed * _deltaTime;
	}
}