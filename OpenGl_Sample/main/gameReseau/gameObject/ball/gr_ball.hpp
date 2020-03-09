#pragma once
#include "main/gameReseau/gameObject/objGameObject/gr_objGameObject.hpp"

class gr_ball : public gr_objGameObject
{
private :
	glm::vec3 velocity;
	std::vector<gr_gameObject> obstacles;
	
public:
	gr_ball(glm::vec3 _position = glm::vec3(), glm::vec3 _rotation = glm::vec3(), glm::vec3 _scale = glm::vec3(1, 1, 1), gr_bounds _bounds = gr_bounds(), const char* _texturePath = "", const char* _vertexShaderPAth = "", const char* _fragmentShaderPath = "", gr_color _color = gr_color(1, 1, 1), std::vector<gr_gameObject> _objects = std::vector<gr_gameObject>());
	gr_ball(const gr_ball& _ball);

	void addVelocity(glm::vec3 _velocity);
	void setVelocity(glm::vec3 _newVelocity);
	glm::vec3 getVelocity() const;
	std::vector<gr_gameObject> getObstacles() const;

	void update() override;
};