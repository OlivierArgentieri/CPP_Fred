#include "gr_rightBorderGameBoard.hpp"


void gr_rightBorderGameBoard::LoadVertices()
{
	#define DEPTH transform.scale.z
	#define WIDTH transform.scale.x
	#define HEIGHT transform.scale.y
	#define SHIFT transform.scale.x

	#define POSX transform.position.x
	#define POSY transform.position.y
	#define POSZ transform.position.z

	// interior
	vertices.push_back(glm::vec3(POSX, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT)); // -WIDTH = shift for hole angle
	vertices.push_back(glm::vec3(POSX, POSY, -DEPTH / 2 + POSZ - SHIFT)); // -WIDTH = shift for hole angle
	vertices.push_back(glm::vec3(POSX, POSY, DEPTH / 2 + POSZ));

	vertices.push_back(glm::vec3(POSX, POSY, DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX, HEIGHT + POSY, DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT)); // -WIDTH = shift for hole angle
	// end interior

	// back
	vertices.push_back(glm::vec3(POSX + WIDTH, HEIGHT + POSY, DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX + WIDTH, POSY, DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX + WIDTH, POSY, -DEPTH / 2 + POSZ - SHIFT)); // -WIDTH = shift for hole angle

	vertices.push_back(glm::vec3(POSX + WIDTH, POSY, -DEPTH / 2 + POSZ - SHIFT)); // -WIDTH = shift for hole angle
	vertices.push_back(glm::vec3(POSX + WIDTH, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT)); // -WIDTH = shift for hole angle
	vertices.push_back(glm::vec3(POSX + WIDTH, HEIGHT + POSY, DEPTH / 2 + POSZ));
	// end back

	// top
	vertices.push_back(glm::vec3(POSX, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT)); // -WIDTH = shift for hole angle
	vertices.push_back(glm::vec3(POSX, HEIGHT + POSY, DEPTH / 2 + POSZ)); 
	vertices.push_back(glm::vec3(POSX + WIDTH, HEIGHT + POSY, DEPTH / 2 + POSZ));

	vertices.push_back(glm::vec3(POSX + WIDTH, HEIGHT + POSY, DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX + WIDTH, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT)); // -WIDTH = shift for hole angle
	vertices.push_back(glm::vec3(POSX, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT)); // -WIDTH = shift for hole angle
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
