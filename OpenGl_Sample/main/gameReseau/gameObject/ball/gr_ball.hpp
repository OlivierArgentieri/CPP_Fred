#pragma once
#include "main/gameReseau/gameObject/objGameObject/gr_objGameObject.hpp"

class gr_ball : public gr_objGameObject
{
private :
	float radius = 0;
	
public:
	gr_ball(const char* _texturePath, const char* _vertexShaderPAth = "", const char* _fragmentShaderPath = "", gr_color _color = gr_color(1,1,1) , float _radius = 1.f);

	float GetRadius() const;
};

