#include "gr_topBorderGameBoard.hpp"

void gr_topBorderGameBoard::LoadVertices()
{
	#define DEPTH transform.scale.z
	#define WIDTH transform.scale.x
	#define HEIGHT transform.scale.y
	#define SHIFT /*transform.scale.z/2*/0

	#define POSX /*transform.position.x*/0
	#define POSY /*transform.position.y*/0
	#define POSZ /*transform.position.z*/0

	// interior
	vertices.push_back(glm::vec3(-WIDTH /2 + POSX - SHIFT, HEIGHT+POSY, POSZ + DEPTH/2));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX - SHIFT, POSY, POSZ + DEPTH / 2));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX, POSY, POSZ + DEPTH / 2));

	vertices.push_back(glm::vec3(WIDTH / 2 + POSX, POSY, POSZ + DEPTH / 2));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX, HEIGHT + POSY, POSZ + DEPTH / 2));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX - SHIFT, HEIGHT + POSY, POSZ + DEPTH / 2));
	// end interior



	// back
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX, HEIGHT + POSY, POSZ - DEPTH/2));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX, POSY, POSZ - DEPTH/2));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX - SHIFT, POSY, POSZ - DEPTH/2));
	
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX - SHIFT, POSY, POSZ - DEPTH/2));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX - SHIFT, HEIGHT + POSY, POSZ - DEPTH/2));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX, HEIGHT + POSY, POSZ - DEPTH/2));
	// end back


	// top
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX - SHIFT, HEIGHT + POSY, POSZ - DEPTH /2));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX - SHIFT, HEIGHT + POSY, POSZ + DEPTH /2));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX, HEIGHT + POSY, POSZ + DEPTH /2));

	vertices.push_back(glm::vec3(WIDTH / 2 + POSX, HEIGHT + POSY, POSZ + DEPTH /2));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX, HEIGHT + POSY, POSZ - DEPTH /2));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX - SHIFT, HEIGHT + POSY, POSZ - DEPTH /2));
	// end top

}

void gr_topBorderGameBoard::LoadUVs()
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

void gr_topBorderGameBoard::LoadNormals()
{
	normals.push_back(glm::vec3(0, 0, -1));
	normals.push_back(glm::vec3(0, 0, 1));
	normals.push_back(glm::vec3(-1, 0, 0));
}

gr_topBorderGameBoard::gr_topBorderGameBoard() : gr_gameObject()
{
	LoadVertices();
	LoadUVs();
	LoadNormals();
}

gr_topBorderGameBoard::gr_topBorderGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, gr_bounds _bounds, const char* _texturePath, const char* _vertexShaderPath, const char* _fragmentShaderPath, gr_color _color) : gr_gameObject(
	_position, _rotation, _scale, _bounds, _texturePath, _vertexShaderPath, _fragmentShaderPath, _color)
{
	LoadVertices();
	LoadUVs();
	LoadNormals();

}

gr_topBorderGameBoard::gr_topBorderGameBoard(const gr_topBorderGameBoard& _leftBorder) : gr_gameObject(_leftBorder)
{
	LoadVertices();
	LoadUVs();
	LoadNormals();

}
