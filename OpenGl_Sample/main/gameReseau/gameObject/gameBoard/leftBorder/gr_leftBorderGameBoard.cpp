#include "gr_leftBorderGameBoard.hpp"

void gr_leftBorderGameBoard::LoadVertices()
{
#define DEPTH transform.scale.z
#define WIDTH transform.scale.x
#define HEIGHT transform.scale.y
#define SHIFT transform.scale.x

#define POSX transform.position.x
#define POSY transform.position.y
#define POSZ transform.position.z
	
	// interior
	vertices.push_back(glm::vec3(POSX, HEIGHT + POSY, DEPTH / 2 + POSZ + SHIFT)); // -SHIFT = shift for hole angle
	vertices.push_back(glm::vec3(POSX, POSY, DEPTH / 2 + POSZ + POSZ + SHIFT)); // -SHIFT = shift for hole angle
	vertices.push_back(glm::vec3(POSX, POSY, -DEPTH / 2 + POSZ));

	vertices.push_back(glm::vec3(POSX, POSY, -DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX, HEIGHT + POSY, -DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX, HEIGHT + POSY, DEPTH / 2 + POSZ + POSZ + SHIFT)); // -SHIFT = shift for hole angle));
	// end interior
	
	
	// back
	vertices.push_back(glm::vec3(POSX - WIDTH , HEIGHT + POSY, -DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX - WIDTH, POSY, -DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX - WIDTH, POSY, DEPTH / 2 + POSZ + SHIFT)); // ** 

	vertices.push_back(glm::vec3(POSX - WIDTH, POSY, DEPTH / 2 + POSZ + SHIFT)); // ** 
	vertices.push_back(glm::vec3(POSX - WIDTH, HEIGHT + POSY, DEPTH / 2 + POSZ + SHIFT)); // **
	vertices.push_back(glm::vec3(POSX - WIDTH, HEIGHT + POSY, -DEPTH / 2 + POSZ)); // **
	// back


	// top
	vertices.push_back(glm::vec3(POSX - WIDTH, HEIGHT + POSY, -DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX - WIDTH, HEIGHT + POSY, DEPTH / 2 + POSZ + SHIFT)); // **
	vertices.push_back(glm::vec3(POSX, HEIGHT + POSY, DEPTH / 2 + POSZ + SHIFT));// **
	
	vertices.push_back(glm::vec3(POSX, HEIGHT +POSY, DEPTH / 2 + POSZ + SHIFT));// **
	vertices.push_back(glm::vec3(POSX, HEIGHT + POSY, -DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX - WIDTH, HEIGHT + POSY, -DEPTH / 2 + POSZ));
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