#include "gr_bottomBorderGameBoard.hpp"



void gr_bottomBorderGameBoard::LoadVertices()
{
	#define DEPTH transform.scale.z
	#define WIDTH transform.scale.x
	#define HEIGHT transform.scale.y
	#define SHIFT transform.scale.z
	
	#define POSX /*transform.position.x*/0
	#define POSY /*transform.position.y*/0
	#define POSZ /*transform.position.z*/0

	// interior
	vertices.push_back(glm::vec3(WIDTH /2 + POSX + SHIFT, HEIGHT + POSY, POSZ));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX + SHIFT, POSY, POSZ));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX, POSY, POSZ));

	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX, POSY, POSZ));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX, HEIGHT + POSY, POSZ));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX + SHIFT, HEIGHT + POSY, POSZ));
	// end interior


	// back
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX, HEIGHT + POSY, POSZ + DEPTH));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX, POSY, POSZ + DEPTH));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX + SHIFT, POSY, POSZ + DEPTH));

	vertices.push_back(glm::vec3(WIDTH / 2 + POSX + SHIFT, POSY, POSZ + DEPTH));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX + SHIFT, HEIGHT + POSY, POSZ + DEPTH));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX, HEIGHT + POSY, POSZ + DEPTH));
	// end back


	
	// top
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX, HEIGHT + POSY, POSZ));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX, HEIGHT + POSY, POSZ + DEPTH));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX + SHIFT, HEIGHT + POSY, POSZ + DEPTH));

	vertices.push_back(glm::vec3(WIDTH / 2 + POSX + SHIFT, HEIGHT + POSY, POSZ + DEPTH));
	vertices.push_back(glm::vec3(WIDTH / 2 + POSX + SHIFT, HEIGHT + POSY, POSZ));
	vertices.push_back(glm::vec3(-WIDTH / 2 + POSX, HEIGHT + POSY, POSZ));
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

gr_bottomBorderGameBoard::gr_bottomBorderGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, gr_bounds _bounds, const char* _texturePath, const char* _vertexShaderPath, const char* _fragmentShaderPath, gr_color _color) : gr_gameObject(
	_position, _rotation, _scale, _bounds, _texturePath, _vertexShaderPath, _fragmentShaderPath, _color)
{
	LoadVertices();
	LoadUVs();
}

gr_bottomBorderGameBoard::gr_bottomBorderGameBoard(const gr_bottomBorderGameBoard& _bottomBorder) : gr_gameObject(_bottomBorder)
{
	LoadVertices();
	LoadUVs();
}
