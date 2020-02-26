#include "gr_bottomBorderGameBoard.hpp"

#define RIGHT_SHIFT transform.scale.z


void gr_bottomBorderGameBoard::LoadVertices()
{
	// interior
	vertices.push_back(glm::vec3(transform.scale.x/2 + transform.position.x +transform.scale.z, transform.scale.y + transform.position.y, transform.position.z));
	vertices.push_back(glm::vec3(transform.scale.x / 2 + transform.position.x + transform.scale.z,  transform.position.y, transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x / 2 + transform.position.x, transform.position.y, transform.position.z));

	vertices.push_back(glm::vec3(-transform.scale.x / 2 + transform.position.x, transform.position.y, transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x / 2 + transform.position.x, transform.scale.y + transform.position.y, transform.position.z));
	vertices.push_back(glm::vec3(transform.scale.x / 2 + transform.position.x + transform.scale.z, transform.scale.y + transform.position.y, transform.position.z));
	// end interior


	// back
	vertices.push_back(glm::vec3(-transform.scale.x / 2 + transform.position.x, transform.scale.y + transform.position.y, transform.position.z + transform.scale.z));
	vertices.push_back(glm::vec3(-transform.scale.x / 2 + transform.position.x, transform.position.y, transform.position.z + transform.scale.z));
	vertices.push_back(glm::vec3(transform.scale.x / 2 + transform.position.x + RIGHT_SHIFT, transform.position.y, transform.position.z + transform.scale.z));

	vertices.push_back(glm::vec3(transform.scale.x / 2 + transform.position.x + RIGHT_SHIFT, transform.position.y, transform.position.z + transform.scale.z));
	vertices.push_back(glm::vec3(transform.scale.x / 2 + transform.position.x + RIGHT_SHIFT,  transform.scale.y+ transform.position.y, transform.position.z + transform.scale.z));
	vertices.push_back(glm::vec3(-transform.scale.x / 2 + transform.position.x, transform.scale.y + transform.position.y, transform.position.z + transform.scale.z));
	// end back


	
	// top
	vertices.push_back(glm::vec3(-transform.scale.x / 2 + transform.position.x, transform.scale.y + transform.position.y, transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x / 2 + transform.position.x, transform.scale.y + transform.position.y, transform.position.z + transform.scale.z));
	vertices.push_back(glm::vec3(transform.scale.x / 2 + transform.position.x + RIGHT_SHIFT, transform.scale.y + transform.position.y, transform.position.z + transform.scale.z));

	vertices.push_back(glm::vec3(transform.scale.x / 2 + transform.position.x + RIGHT_SHIFT, transform.scale.y + transform.position.y, transform.position.z + transform.scale.z));
	vertices.push_back(glm::vec3(transform.scale.x / 2 + transform.position.x + RIGHT_SHIFT, transform.scale.y + transform.position.y, transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x / 2 + transform.position.x, transform.scale.y + transform.position.y, transform.position.z));
	//end top

}

void gr_bottomBorderGameBoard::LoadUVs()
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

gr_bottomBorderGameBoard::gr_bottomBorderGameBoard()
{
	LoadVertices();
	LoadUVs();
}

gr_bottomBorderGameBoard::gr_bottomBorderGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale) : gr_gameObject(_position, _rotation, _scale)
{
	LoadVertices();
	LoadUVs();
}

gr_bottomBorderGameBoard::gr_bottomBorderGameBoard(const gr_bottomBorderGameBoard& _bottomBorder) : gr_gameObject(_bottomBorder.transform.position, _bottomBorder.transform.rotation, _bottomBorder.transform.scale)
{
	LoadVertices();
	LoadUVs();
}
