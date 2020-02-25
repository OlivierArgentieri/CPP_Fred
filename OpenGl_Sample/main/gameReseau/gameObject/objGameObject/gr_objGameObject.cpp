#include "gr_objGameObject.hpp"
#include "common/objloader.hpp"


gr_objGameObject::gr_objGameObject(const char* _pathToObj) : gr_gameObject()
{
	bool test = loadOBJ(_pathToObj, gr_gameObject::vertices, gr_gameObject::uvs, gr_gameObject::normals);
}