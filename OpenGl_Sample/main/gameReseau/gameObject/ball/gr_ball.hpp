#pragma once
#include "main/gameReseau/gameObject/objGameObject/gr_objGameObject.hpp"

class gr_ball : public gr_objGameObject
{
private :
	glm::vec3 velocity;
	
public:
	gr_ball(glm::vec3 _position = glm::vec3(), glm::vec3 _rotation = glm::vec3(), glm::vec3 _scale = glm::vec3(1,1,1), const char* _texturePath = "", const char* _vertexShaderPAth = "", const char* _fragmentShaderPath = "", gr_color _color = gr_color(1,1,1));
	gr_ball(const gr_ball& _ball);

	void addVelocity(glm::vec3 _velocity);
	glm::vec3 getVelocity() const;

	void update() override;
};