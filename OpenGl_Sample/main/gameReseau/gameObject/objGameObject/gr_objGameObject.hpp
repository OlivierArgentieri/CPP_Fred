#pragma once
#include <main/gameReseau/gameObject/gr_gameObject.hpp>

/// create gameObject from .obj file
class gr_objGameObject : public gr_gameObject
{
public:
	gr_objGameObject(const char* _pathToObj);
};