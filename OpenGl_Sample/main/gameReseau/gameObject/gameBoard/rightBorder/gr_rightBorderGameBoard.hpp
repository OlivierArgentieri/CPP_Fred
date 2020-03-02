#pragma once

#include "main/gameReseau/gameObject/gr_gameObject.hpp"

class gr_rightBorderGameBoard : public gr_gameObject
{
private:
	void LoadVertices();
	void LoadUVs();


public:
	gr_rightBorderGameBoard();
	gr_rightBorderGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, const char* _texturePath = "", const char* _vertexShaderPath = "", const char* _fragmentShaderPath = "", gr_color _color = gr_color());
	gr_rightBorderGameBoard(const gr_rightBorderGameBoard& _rightBorder);
};