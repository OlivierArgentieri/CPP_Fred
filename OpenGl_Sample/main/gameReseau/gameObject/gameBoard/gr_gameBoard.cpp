#include "gr_gameBoard.hpp"
#include "plane/gr_planeGameBoard.hpp"

void gr_gameBoard::CreatePlane()
{
	plane = gr_planeGameBoard(glm::vec3(), glm::vec3(), glm::vec3(100, 0, 100));
}

void gr_gameBoard::CreateBorders()
{
	leftBorder = gr_leftBorderGameBoard(glm::vec3(-50,0,0), glm::vec3(), glm::vec3(10, 10, 100));
	rightBorder = gr_rightBorderGameBoard(glm::vec3(50,0,0), glm::vec3(), glm::vec3(10, 10, 100));
	bottomBorder= gr_bottomBorderGameBoard(glm::vec3(0,0,50), glm::vec3(), glm::vec3(100, 10, 10));
}


gr_gameBoard::gr_gameBoard() : gr_gameObject(glm::vec3(), glm::vec3(), glm::vec3())
{
	CreatePlane();
	CreateBorders();
}

void gr_gameBoard::Draw()
{
	plane.Draw();
	leftBorder.Draw();
	rightBorder.Draw();
	bottomBorder.Draw();
}