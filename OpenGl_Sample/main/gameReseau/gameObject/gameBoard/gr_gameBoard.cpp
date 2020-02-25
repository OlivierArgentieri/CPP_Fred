#include "gr_gameBoard.hpp"
#include "plane/gr_planeGameBoard.hpp"

void gr_gameBoard::CreatePlane()
{
	plane = gr_planeGameBoard(glm::vec3(), glm::vec3(), glm::vec3(100, 0, 100));
	
}

void gr_gameBoard::CreateUVS()
{
	uvs.push_back(glm::vec2(0, 0));
	uvs.push_back(glm::vec2(0, 1));
	uvs.push_back(glm::vec2(1, 1));

	uvs.push_back(glm::vec2(1, 1));
	uvs.push_back(glm::vec2(1, 0));
	uvs.push_back(glm::vec2(0, 0));
}

gr_gameBoard::gr_gameBoard() : gr_gameObject(glm::vec3(), glm::vec3(), glm::vec3())
{
	CreatePlane();
	CreateUVS();
}

void gr_gameBoard::Draw()
{
	plane.Draw();
}
