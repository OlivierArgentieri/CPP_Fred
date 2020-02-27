#pragma once
#include <main/gameReseau/gameObject/gr_gameObject.hpp>

/// create gameObject from .obj file
class gr_objGameObject : public gr_gameObject
{
public:
	gr_objGameObject(const char* _pathToObj, const char* _texturePath = "");
	gr_objGameObject(const char* _pathToObj, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, const char* _texturePath = "");
};