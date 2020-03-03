#include "gr_objGameObject.hpp"
#include "common/objloader.hpp"


gr_objGameObject::gr_objGameObject(const char* _pathToObj, const char* _texturePath, const char* _vertexShaderPath, const char* _fragmentShaderPath, gr_color _color) : gr_objGameObject(_pathToObj, glm::vec3(), glm::vec3(), glm::vec3(), _texturePath, _vertexShaderPath, _fragmentShaderPath, _color)
{
}

gr_objGameObject::gr_objGameObject(const char* _pathToObj, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, const char* _texturePath, const char* _vertexShaderPath, const char* _fragmentShaderPath, gr_color _color) : gr_gameObject(
	_position, _rotation, _scale, _texturePath, _vertexShaderPath, _fragmentShaderPath, _color)
{
	bool _test = loadOBJ(_pathToObj, gr_gameObject::vertices, gr_gameObject::uvs, gr_gameObject::normals);
	texturePath = _texturePath;
	fragmentShaderPath = _fragmentShaderPath;
	vertexShaderPath = _vertexShaderPath;
	pathOBJ = _pathToObj;
}

gr_objGameObject::gr_objGameObject(const gr_objGameObject& _obj) : gr_gameObject(
	_obj.transform.position, _obj.transform.rotation, _obj.transform.scale, _obj.texturePath, _obj.vertexShaderPath, _obj.fragmentShaderPath, _obj.Color)
{
	bool _test = loadOBJ(_obj.pathOBJ, gr_gameObject::vertices, gr_gameObject::uvs, gr_gameObject::normals);
	pathOBJ = _obj.pathOBJ;
}
