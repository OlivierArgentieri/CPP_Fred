#include "gr_gameBoard.hpp"
#include "plane/gr_planeGameBoard.hpp"
#include "topBorder/gr_topBorderGameBoard.hpp"

#define WALL_HEIGHT 10

void gr_gameBoard::CreatePlane()
{
	plane = gr_planeGameBoard(glm::vec3(), glm::vec3(), glm::vec3(100, 0, 100), "", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(0,1,0));
}

void gr_gameBoard::CreateBorders()
{
	/*
	leftBorder = gr_leftBorderGameBoard(glm::vec3(-50,0,0), glm::vec3(), glm::vec3(10, WALL_HEIGHT, 100), "color.dds");
	rightBorder = gr_rightBorderGameBoard(glm::vec3(50,0,0), glm::vec3(), glm::vec3(10, WALL_HEIGHT, 100),"color.dds" );
	bottomBorder = gr_bottomBorderGameBoard(glm::vec3(0,0,50), glm::vec3(), glm::vec3(100, WALL_HEIGHT, 10), "color.dds");
	topBorder = gr_topBorderGameBoard(glm::vec3(0,0,-50), glm::vec3(), glm::vec3(100, WALL_HEIGHT, 10), "color.dds");*/
}


gr_gameBoard::gr_gameBoard() : gr_gameObject(glm::vec3(), glm::vec3(), glm::vec3(), "", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader" , gr_color(0, 0, 0))
{
	CreatePlane();
	CreateBorders();	
}

gr_gameBoard::gr_gameBoard(const gr_gameBoard& _gameBoard) : gr_gameObject(_gameBoard)
{
}

void gr_gameBoard::Draw()
{
	plane.Draw();
	//lane.SetColorShader(gr_color(1, 0, 0));
	/*
	leftBorder.Draw();
	
	rightBorder.Draw();
	bottomBorder.Draw();
	topBorder.Draw();*/
}

void gr_gameBoard::UseShader(GLint _shaderID)
{
	// Use our shader
	glUseProgram(_shaderID); // todo in game object
	MatrixID = glGetUniformLocation(_shaderID, "MVP");
}