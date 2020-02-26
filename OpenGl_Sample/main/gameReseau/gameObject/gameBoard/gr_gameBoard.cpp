#include "gr_gameBoard.hpp"
#include "plane/gr_planeGameBoard.hpp"

void gr_gameBoard::CreatePlane()
{
	plane = gr_planeGameBoard(glm::vec3(), glm::vec3(), glm::vec3(100, 0, 100));
}

void gr_gameBoard::CreateLeftBorder()
{
	leftBorder = gr_leftBorderGameBoard(glm::vec3(), glm::vec3(), glm::vec3(100, 10, 100));
}


gr_gameBoard::gr_gameBoard() : gr_gameObject(glm::vec3(), glm::vec3(), glm::vec3())
{
	CreatePlane();
	CreateLeftBorder();
}

void gr_gameBoard::Draw()
{
	plane.Draw();
	leftBorder.Draw();
}