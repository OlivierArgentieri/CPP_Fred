#include "gr_gameBoard.hpp"
#include "plane/gr_planeGameBoard.hpp"
#include "topBorder/gr_topBorderGameBoard.hpp"

#define WALL_HEIGHT 20

void gr_gameBoard::CreatePlane()
{
	plane = gr_planeGameBoard(glm::vec3(), glm::vec3(), glm::vec3(100, 0, 100), "UVChecker.dds");
}

void gr_gameBoard::CreateBorders()
{
	leftBorder = gr_leftBorderGameBoard(glm::vec3(-50,0,0), glm::vec3(), glm::vec3(10, WALL_HEIGHT, 100), "UVChecker.dds");
	rightBorder = gr_rightBorderGameBoard(glm::vec3(50,0,0), glm::vec3(), glm::vec3(10, WALL_HEIGHT, 100),"UVChecker.dds" );
	bottomBorder = gr_bottomBorderGameBoard(glm::vec3(0,0,50), glm::vec3(), glm::vec3(100, WALL_HEIGHT, 10), "UVChecker.dds");
	topBorder = gr_topBorderGameBoard(glm::vec3(0,0,-50), glm::vec3(), glm::vec3(100, WALL_HEIGHT, 10), "UVChecker.dds");
}


gr_gameBoard::gr_gameBoard() : gr_gameObject(glm::vec3(), glm::vec3(), glm::vec3(), "UVChecker.dds")
{
	CreatePlane();
	CreateBorders();	
}

gr_gameBoard::gr_gameBoard(const gr_gameBoard& _gameBoard) : gr_gameObject(_gameBoard)
{
}

void gr_gameBoard::Draw()
{
	//LoadTexture("aaa.dds");
	plane.Draw();
	
	leftBorder.Draw();
	
	rightBorder.Draw();
	bottomBorder.Draw();
	topBorder.Draw();
}
