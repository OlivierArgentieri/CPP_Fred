#include "gr_gameBoard.hpp"

#include "main/gameReseau/window/gr_window.hpp"
#include "plane/gr_planeGameBoard.hpp"
#include "topBorder/gr_topBorderGameBoard.hpp"

#define WALL_HEIGHT 10
#define WIDTH 100
#define HEIGHT 100


void gr_gameBoard::CreatePlane()
{
	plane = gr_planeGameBoard(glm::vec3(), glm::vec3(), glm::vec3(WIDTH, 0, HEIGHT), gr_bounds(), "", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(65,105,225));
}


void gr_gameBoard::CreateBorders()
{
	leftBorder = gr_leftBorderGameBoard(glm::vec3(-50,0,0), glm::vec3(), glm::vec3(10, WALL_HEIGHT, 100), gr_bounds(glm::vec3(10, WALL_HEIGHT, 100), glm::vec3()), "uvChecker.dds", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(0, 1, 0));
	rightBorder = gr_rightBorderGameBoard(glm::vec3(50,0,0), glm::vec3(), glm::vec3(10, WALL_HEIGHT, 100), gr_bounds(glm::vec3(10, WALL_HEIGHT, 100), glm::vec3()), "","TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(1, 1, 0));
	bottomBorder = gr_bottomBorderGameBoard(glm::vec3(0,0,50), glm::vec3(), glm::vec3(100, WALL_HEIGHT, 10), gr_bounds(glm::vec3(100, WALL_HEIGHT, 10), glm::vec3()), "","TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(0.5f, 0.3f, 0));
	topBorder = gr_topBorderGameBoard(glm::vec3(0,0,-50), glm::vec3(), glm::vec3(100, WALL_HEIGHT, 10), gr_bounds(glm::vec3(100, WALL_HEIGHT, 10), glm::vec3()),"" , "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(1, 0.5, 0));
}

gr_gameBoard::gr_gameBoard() : gr_gameObject(glm::vec3(), glm::vec3(), glm::vec3(), gr_bounds(),  "", "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader", gr_color(0, 0, 0))
{
	CreatePlane();
	CreateBorders();	
}

gr_gameBoard::gr_gameBoard(const gr_gameBoard& _gameBoard) : gr_gameObject(_gameBoard)
{
}

void gr_gameBoard::draw(gr_window* _window)
{
	if (!_window) return;
	plane.draw(_window);

	leftBorder.draw(_window);

	rightBorder.draw(_window);
	bottomBorder.draw(_window);
	topBorder.draw(_window);
}

std::vector<gr_gameObject> gr_gameBoard::getElementComposed()
{
	return std::vector<gr_gameObject>
	{
		leftBorder,
		rightBorder,
		bottomBorder,
		topBorder
	};
}