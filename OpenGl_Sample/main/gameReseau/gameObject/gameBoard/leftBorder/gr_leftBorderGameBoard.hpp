#pragma once
#include "main/gameReseau/gameObject/gr_gameObject.hpp"

class gr_leftBorderGameBoard : public gr_gameObject
{
private:
	void LoadVertices();
	void LoadUVs();
	
public:
	gr_leftBorderGameBoard();
	gr_leftBorderGameBoard(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, const char* _texturePath = "", const char* _vertexShaderPath = "", const char* _fragmentShaderPath = "", gr_color _color = gr_color());
	gr_leftBorderGameBoard(const gr_leftBorderGameBoard& _leftBorder);
};