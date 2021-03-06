#pragma once
#include <main/gameReseau/gameObject/gr_gameObject.hpp>

/// create gameObject from .obj file
class gr_objGameObject : public gr_gameObject
{
private :
	const char* pathOBJ;
public:
	
	gr_objGameObject(const char* _pathToObj, const char* _texturePath = "", const char* _vertexShaderPath = "", const char* _fragmentShaderPath = "", gr_color _color = gr_color());
	gr_objGameObject(const char* _pathToObj = "", glm::vec3 _position = glm::vec3(), glm::vec3 _rotation = glm::vec3(), glm::vec3 _scale = glm::vec3(), gr_bounds _bounds = gr_bounds(), const char* _texturePath = "", const char* _vertexShaderPath = "", const char* _fragmentShaderPath = "", gr_color _color = gr_color());
	gr_objGameObject(const gr_objGameObject& _obj);
};