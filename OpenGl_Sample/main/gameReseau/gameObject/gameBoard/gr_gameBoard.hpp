#pragma once
#include "main/gameReseau/gameObject/gr_gameObject.hpp"
#include "plane/gr_planeGameBoard.hpp"
#include "leftBorder/gr_leftBorderGameBoard.hpp"
#include "rightBorder/gr_rightBorderGameBoard.hpp"
#include "bottomBorder/gr_bottomBorderGameBoard.hpp"

class gr_gameBoard : public gr_gameObject
{
private:
	gr_planeGameBoard plane;
	gr_leftBorderGameBoard leftBorder;
	gr_rightBorderGameBoard rightBorder;
	gr_bottomBorderGameBoard bottomBorder;
	
	void CreatePlane();
	void CreateBorders();

public:
	gr_gameBoard();
	void Draw() override;
};
