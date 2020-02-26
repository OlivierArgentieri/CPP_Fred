#pragma once

#include "main/gameReseau/gameObject/gr_gameObject.hpp"

class gr_rightBorderGameBoard : public gr_gameObject
{
private:
	void LoadVertices();
	void LoadUVs();


public:
	gr_rightBorderGameBoard();
	gr_rightBorderGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
	gr_rightBorderGameBoard(const gr_rightBorderGameBoard& _rightBorder);
};