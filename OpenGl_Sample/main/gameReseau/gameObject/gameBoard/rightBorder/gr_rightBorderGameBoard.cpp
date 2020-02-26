#include "gr_rightBorderGameBoard.hpp"


void gr_rightBorderGameBoard::LoadVertices()
{
	// interior
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z - transform.scale.x)); // -transform.scale.x = shift for hole angle
	vertices.push_back(glm::vec3(transform.position.x, transform.position.y, -transform.scale.z / 2 + transform.position.z - transform.scale.x)); // -transform.scale.x = shift for hole angle
	vertices.push_back(glm::vec3(transform.position.x, transform.position.y, transform.scale.z / 2 + transform.position.z));

	vertices.push_back(glm::vec3(transform.position.x, transform.position.y, transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z - transform.scale.x)); // -transform.scale.x = shift for hole angle
	// end interior

	// back
	vertices.push_back(glm::vec3(transform.position.x + transform.scale.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(transform.position.x + transform.scale.x, transform.position.y, transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(transform.position.x + transform.scale.x, transform.position.y, -transform.scale.z / 2 + transform.position.z - transform.scale.x)); // -transform.scale.x = shift for hole angle

	vertices.push_back(glm::vec3(transform.position.x + transform.scale.x, transform.position.y, -transform.scale.z / 2 + transform.position.z - transform.scale.x)); // -transform.scale.x = shift for hole angle
	vertices.push_back(glm::vec3(transform.position.x + transform.scale.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z - transform.scale.x)); // -transform.scale.x = shift for hole angle
	vertices.push_back(glm::vec3(transform.position.x + transform.scale.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z));
	// end back

	// top
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z - transform.scale.x)); // -transform.scale.x = shift for hole angle
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z)); 
	vertices.push_back(glm::vec3(transform.position.x + transform.scale.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z));

	vertices.push_back(glm::vec3(transform.position.x + transform.scale.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(transform.position.x + transform.scale.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z - transform.scale.x)); // -transform.scale.x = shift for hole angle
	vertices.push_back(glm::vec3(transform.position.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z - transform.scale.x)); // -transform.scale.x = shift for hole angle
	// end top
}

void gr_rightBorderGameBoard::LoadUVs()
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

gr_rightBorderGameBoard::gr_rightBorderGameBoard() : gr_gameObject()
{
	LoadVertices();
	LoadUVs();
}

gr_rightBorderGameBoard::gr_rightBorderGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) : gr_gameObject(_position, _rotation, _scale)
{
	LoadVertices();
	LoadUVs();
}

gr_rightBorderGameBoard::gr_rightBorderGameBoard(const gr_rightBorderGameBoard& _rightBorder) : gr_gameObject(_rightBorder.transform.position, _rightBorder.transform.rotation, _rightBorder.transform.scale)
{
	LoadVertices();
	LoadUVs();
}
