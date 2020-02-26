#pragma once
#include "main/gameReseau/gameObject/gr_gameObject.hpp"

class gr_bottomBorderGameBoard : public gr_gameObject
{

private:
	void LoadVertices();
	void LoadUVs();


public:
	gr_bottomBorderGameBoard();
	gr_bottomBorderGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
	gr_bottomBorderGameBoard(const gr_bottomBorderGameBoard& _bottomBorder);

};
