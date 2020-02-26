#include "gr_leftBorderGameBoard.hpp"

void gr_leftBorderGameBoard::LoadVertices()
{
	// interior
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z + transform.scale.x)); // -transform.scale.x = shift for hole angle
	vertices.push_back(glm::vec3(transform.position.x, transform.position.y, transform.scale.z / 2 + transform.position.z + transform.position.z + transform.scale.x)); // -transform.scale.x = shift for hole angle
	vertices.push_back(glm::vec3(transform.position.x, transform.position.y, -transform.scale.z / 2 + transform.position.z));

	vertices.push_back(glm::vec3(transform.position.x, transform.position.y, -transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z + transform.position.z + transform.scale.x)); // -transform.scale.x = shift for hole angle));
	// end interior
	
	
	// back
	vertices.push_back(glm::vec3(transform.position.x - transform.scale.x , transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(transform.position.x - transform.scale.x, transform.position.y, -transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(transform.position.x - transform.scale.x, transform.position.y, transform.scale.z / 2 + transform.position.z + transform.scale.x)); // ** 

	vertices.push_back(glm::vec3(transform.position.x - transform.scale.x, transform.position.y, transform.scale.z / 2 + transform.position.z + transform.scale.x)); // ** 
	vertices.push_back(glm::vec3(transform.position.x - transform.scale.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z + transform.scale.x)); // **
	vertices.push_back(glm::vec3(transform.position.x - transform.scale.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z)); // **
	// back


	// top
	vertices.push_back(glm::vec3(transform.position.x - transform.scale.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(transform.position.x - transform.scale.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z + transform.scale.x)); // **
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z + transform.scale.x));// **
	
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y +transform.position.y, transform.scale.z / 2 + transform.position.z + transform.scale.x));// **
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(transform.position.x - transform.scale.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z));
	// end top
}

void gr_leftBorderGameBoard::LoadUVs()
{
	
	uvs.push_back(glm::vec2(0, 0));
	uvs.push_back(glm::vec2(0, 1));
	uvs.push_back(glm::vec2(1, 1));

	uvs.push_back(glm::vec2(1, 1));
	uvs.push_back(glm::vec2(1, 0));
	uvs.push_back(glm::vec2(0, 0));
	
	
	uvs.push_back(glm::vec2(0, 0));
	uvs.push_back(glm::vec2(0, 1));
	uvs.push_back(glm::vec2(1, 1));

	uvs.push_back(glm::vec2(1, 1));
	uvs.push_back(glm::vec2(1, 0));
	uvs.push_back(glm::vec2(0, 0));

	
	uvs.push_back(glm::vec2(0, 0));
	uvs.push_back(glm::vec2(0, 1));
	uvs.push_back(glm::vec2(1, 1));

	uvs.push_back(glm::vec2(1, 1));
	uvs.push_back(glm::vec2(1, 0));
	uvs.push_back(glm::vec2(0, 0));


}

gr_leftBorderGameBoard::gr_leftBorderGameBoard() : gr_gameObject()
{
	LoadVertices();
	LoadUVs();
}

gr_leftBorderGameBoard::gr_leftBorderGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) : gr_gameObject(_position, _rotation, _scale)
{
	LoadVertices();
	LoadUVs();
}

gr_leftBorderGameBoard::gr_leftBorderGameBoard(const gr_leftBorderGameBoard& _leftBorder) : gr_gameObject(_leftBorder.transform.position, _leftBorder.transform.rotation, _leftBorder.transform.scale)
{
	LoadVertices();
	LoadUVs();
}