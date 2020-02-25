#pragma once
#include "main/gameReseau/gameObject/gr_gameObject.hpp"
#include "plane/gr_planeGameBoard.hpp"

class gr_gameBoard : public gr_gameObject
{
private:
	gr_planeGameBoard plane;
	
	void CreatePlane();
	void CreateUVS();

public:
	gr_gameBoard();
	void Draw() override;
};
