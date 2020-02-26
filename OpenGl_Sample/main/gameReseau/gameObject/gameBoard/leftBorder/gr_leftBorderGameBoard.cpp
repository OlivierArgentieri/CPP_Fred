#include "gr_leftBorderGameBoard.hpp"

void gr_leftBorderGameBoard::LoadVertices()
{
	/**/
	// interior
	vertices.push_back(glm::vec3(-transform.scale.x /2 + transform.position.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x / 2 + transform.position.x,0, transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x / 2 + transform.position.x, 0, -transform.scale.z / 2 + transform.position.z));

	vertices.push_back(glm::vec3(-transform.scale.x/2 + transform.position.x, 0, -transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x/2 + transform.position.x, transform.scale.y + transform.position.y, -transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x/2 + transform.position.x, transform.scale.y + transform.position.y, transform.scale.z / 2 + transform.position.z));
	// end interior
	

	// back
	/*
	vertices.push_back(glm::vec3(-transform.scale.x/2 + transform.position.x, transform.position.y, -transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x/2 + transform.position.x, transform.scale.y / 2 + transform.position.y, -transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x/2 + transform.position.x, transform.scale.y / 2 + transform.position.y, transform.scale.z / 2 + transform.position.z));
	
	vertices.push_back(glm::vec3(-transform.scale.x/2 + transform.position.x, transform.scale.y / 2 + transform.position.y, transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x/2 + transform.position.x, transform.position.y, transform.scale.z / 2 + transform.position.z));
	vertices.push_back(glm::vec3(-transform.scale.x/2 + transform.position.x, transform.position.y, -transform.scale.z / 2 + transform.position.z));
	*/// back top

	
	// back
	vertices.push_back(glm::vec3(-60, 10, -50));
	vertices.push_back(glm::vec3(-60, 0, -50 ));
	vertices.push_back(glm::vec3(-60, 0, 60)); //

	vertices.push_back(glm::vec3(-60, 0, 60 )); //
	vertices.push_back(glm::vec3(-60, 10, 60 )); //
	vertices.push_back(glm::vec3(-60, 10, -50)); //
	// back

	//top
/*
	vertices.push_back(glm::vec3(-50, 10, 50));
	vertices.push_back(glm::vec3(-50, 10, -50));
	vertices.push_back(glm::vec3(-60, 10, -50));
	
	vertices.push_back(glm::vec3(-60, 10, -50));
	vertices.push_back(glm::vec3(-60, 10, 50));
	vertices.push_back(glm::vec3(-50, 10, 50));

	
	vertices.push_back(glm::vec3(-50, 10, -50));
	vertices.push_back(glm::vec3(-60, 10, -50));
	vertices.push_back(glm::vec3(-60, 10, 50));
								  
	vertices.push_back(glm::vec3(-60, 10, 50));

	vertices.push_back(glm::vec3(-50, 10, 50));
	vertices.push_back(glm::vec3(-50, 10, -50));*/

	vertices.push_back(glm::vec3(-60, 10, -50));
	vertices.push_back(glm::vec3(-60, 10, 50));
	vertices.push_back(glm::vec3(-50, 10, 50));
	
	vertices.push_back(glm::vec3(-50, 10, 50));
	vertices.push_back(glm::vec3(-50, 10, -50));
	vertices.push_back(glm::vec3(-60, 10, -50));

	//end top
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
	uvs.push_back(glm::vec2(0, 0));/**/


/*	uvs.push_back(glm::vec2(0, 0));
	uvs.push_back(glm::vec2(0, -1));
	uvs.push_back(glm::vec2(-1, -1));
	
	uvs.push_back(glm::vec2(-1, -1));
	uvs.push_back(glm::vec2(-1, 1));
	uvs.push_back(glm::vec2(0, 0));	*/

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