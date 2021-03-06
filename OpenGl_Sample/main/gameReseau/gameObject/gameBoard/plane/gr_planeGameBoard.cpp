#include "gr_planeGameBoard.hpp"

void gr_planeGameBoard::CreateVertices()
{
	
	// plane
	vertices.push_back(glm::vec3(-(transform.scale.x / 2) + transform.position.x,
	                             (transform.scale.y / 2) + transform.position.y,
	                             -(transform.scale.z / 2) + transform.position.z));
	vertices.push_back(glm::vec3(-(transform.scale.x / 2) + transform.position.x,
	                             (transform.scale.y / 2) + transform.position.y,
	                             (transform.scale.z / 2) + transform.position.z));
	vertices.push_back(glm::vec3((transform.scale.x / 2) + transform.position.x,
	                             (transform.scale.y / 2) + transform.position.y,
	                             (transform.scale.z / 2) + transform.position.z));

	vertices.push_back(glm::vec3((transform.scale.x / 2) + transform.position.x,
	                             (transform.scale.y / 2) + transform.position.y,
	                             (transform.scale.z / 2) + transform.position.z));
	vertices.push_back(glm::vec3((transform.scale.x / 2) + transform.position.x,
	                             (transform.scale.y / 2) + transform.position.y,
	                             -(transform.scale.z / 2) + transform.position.z));
	vertices.push_back(glm::vec3(-(transform.scale.x / 2) + transform.position.x,
	                             (transform.scale.y / 2) + transform.position.y,
	                             -(transform.scale.z / 2) + transform.position.z));
	//  end plane
	glEnd();
}

void gr_planeGameBoard::CreateUVS()
{
	uvs.push_back(glm::vec2(0, 0));
	uvs.push_back(glm::vec2(0, 1));
	uvs.push_back(glm::vec2(1, 1));

	uvs.push_back(glm::vec2(1, 1));
	uvs.push_back(glm::vec2(1, 0));
	uvs.push_back(glm::vec2(0, 0));
}


gr_planeGameBoard::gr_planeGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, gr_bounds _bounds, const char* _texturePath, const char* _vertexShaderPath, const char* _fragmentShaderPath, gr_color _color) : gr_gameObject(
	_position, _rotation, _scale, _bounds, _texturePath, _vertexShaderPath, _fragmentShaderPath, _color)
{
	CreateVertices();
	CreateUVS();
}

gr_planeGameBoard::gr_planeGameBoard() : gr_gameObject()
{
	CreateVertices();
	CreateUVS();

}

gr_planeGameBoard::gr_planeGameBoard(const gr_planeGameBoard& _plane) : gr_gameObject(_plane)
{
	CreateVertices();
	CreateUVS();

}