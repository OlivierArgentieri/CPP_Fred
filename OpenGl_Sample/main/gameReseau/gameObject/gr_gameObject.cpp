#include "gr_gameObject.hpp"
#include "main/gameReseau/renderer/gr_renderer.hpp"


void gr_gameObject::LoadTexture()
{
	// Load the texture
	//Texture = loadDDS("uvmap.DDS"); // todo 
	Texture = loadDDS("UVChecker.dds"); // todo 

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