#pragma once
#include "main/gameReseau/gameObject/gr_gameObject.hpp"
#include "plane/gr_planeGameBoard.hpp"
#include "leftBorder/gr_leftBorderGameBoard.hpp"

class gr_gameBoard : public gr_gameObject
{
private:
	gr_planeGameBoard plane;
	gr_leftBorderGameBoard leftBorder;
	
	void CreatePlane();
	void CreateLeftBorder();

public:
	gr_gameBoard();
	void Draw() override;
};
