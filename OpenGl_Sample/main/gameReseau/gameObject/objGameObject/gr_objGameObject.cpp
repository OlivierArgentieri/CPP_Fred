#include "gr_objGameObject.hpp"
#include "common/objloader.hpp"


gr_objGameObject::gr_objGameObject(const char* _pathToObj, const char* _texturePath, const char* _vertexShaderPath, const char* _fragmentShaderPath, gr_color _color) : gr_objGameObject(_pathToObj, glm::vec3(), glm::vec3(), glm::vec3(), _texturePath, _vertexShaderPath, _fragmentShaderPath, _color)
{
}

gr_objGameObject::gr_objGameObject(const char* _pathToObj, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, const char* _texturePath, const char* _vertexShaderPath, const char* _fragmentShaderPath, gr_color _color) : gr_gameObject(_position, _rotation, _scale, _texturePath, _vertexShaderPath, _fragmentShaderPath, _color)
{
	bool test = loadOBJ(_pathToObj, gr_gameObject::vertices, gr_gameObject::uvs, gr_gameObject::normals);
}