#pragma once
#include "main/gameReseau/gameObject/gr_gameObject.hpp"

class gr_planeGameBoard : public gr_gameObject
{
private:
	void CreateVertices();
	void CreateUVS();
	
public:
	gr_planeGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, const char* _texturePath = "");
	gr_planeGameBoard();
	gr_planeGameBoard(const gr_planeGameBoard& _plane);
};