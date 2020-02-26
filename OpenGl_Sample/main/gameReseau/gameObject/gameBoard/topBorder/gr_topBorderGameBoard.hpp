#pragma once

#include "main/gameReseau/gameObject/gr_gameObject.hpp"

class gr_topBorderGameBoard : public gr_gameObject
{
private:
	void LoadVertices();
	void LoadUVs();
public:
	gr_topBorderGameBoard();
	gr_topBorderGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
	gr_topBorderGameBoard(const gr_topBorderGameBoard& _leftBorder);

};