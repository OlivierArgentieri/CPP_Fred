#include "gr_rightBorderGameBoard.hpp"


void gr_rightBorderGameBoard::LoadVertices()
{
	#define DEPTH transform.scale.z
	#define WIDTH transform.scale.x
	#define HEIGHT transform.scale.y
	#define SHIFT transform.scale.x
	
	#define POSX /*transform.position.x*/0
	#define POSY /*transform.position.y*/0
	#define POSZ /*transform.position.z*/0
	
	// interior
	vertices.push_back(glm::vec3(POSX - WIDTH / 2, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT)); // -SHIFT = shift for hole angle
	vertices.push_back(glm::vec3(POSX - WIDTH / 2, POSY, -DEPTH / 2 + POSZ - SHIFT)); // -SHIFT = shift for hole angle
	vertices.push_back(glm::vec3(POSX - WIDTH / 2, POSY, DEPTH / 2 + POSZ));
									  
	vertices.push_back(glm::vec3(POSX - WIDTH / 2, POSY, DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX - WIDTH / 2, HEIGHT + POSY, DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX - WIDTH / 2, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT)); // -SHIFT = shift for hole angle
	// end interior

	// back
	vertices.push_back(glm::vec3(POSX + WIDTH /2, HEIGHT + POSY, DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX + WIDTH /2, POSY, DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX + WIDTH /2, POSY, -DEPTH / 2 + POSZ - SHIFT)); // -SHIFT = shift for hole angle

	vertices.push_back(glm::vec3(POSX + WIDTH/ 2, POSY, -DEPTH / 2 + POSZ - SHIFT)); // -SHIFT = shift for hole angle
	vertices.push_back(glm::vec3(POSX + WIDTH/ 2, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT)); // -SHIFT = shift for hole angle
	vertices.push_back(glm::vec3(POSX + WIDTH/ 2, HEIGHT + POSY, DEPTH / 2 + POSZ));
	// end back

		// top
	vertices.push_back(glm::vec3(POSX - WIDTH / 2, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT)); // **
	vertices.push_back(glm::vec3(POSX - WIDTH / 2, HEIGHT + POSY, DEPTH / 2 + POSZ)); 
	vertices.push_back(glm::vec3(POSX + WIDTH / 2, HEIGHT + POSY, DEPTH / 2 + POSZ));

	vertices.push_back(glm::vec3(POSX + WIDTH / 2, HEIGHT + POSY, DEPTH / 2 + POSZ));
	vertices.push_back(glm::vec3(POSX + WIDTH / 2, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT));// **
	vertices.push_back(glm::vec3(POSX - WIDTH / 2, HEIGHT + POSY, -DEPTH / 2 + POSZ - SHIFT));// **
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

gr_rightBorderGameBoard::gr_rightBorderGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, gr_bounds _bounds, const char* _texturePath, const char* _vertexShaderPath, const char* _fragmentShaderPath, gr_color _color) : gr_gameObject(
	_position, _rotation, _scale, _bounds, _texturePath, _vertexShaderPath, _fragmentShaderPath, _color)
{
	LoadVertices();
	LoadUVs();
}

gr_rightBorderGameBoard::gr_rightBorderGameBoard(const gr_rightBorderGameBoard& _rightBorder) : gr_gameObject(_rightBorder)
{
	LoadVertices();
	LoadUVs();
}
