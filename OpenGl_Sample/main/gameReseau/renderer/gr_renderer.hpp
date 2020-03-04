#include <glm/detail/type_vec3.hpp>
#include <vector>
#include <glm/glm.hpp>

#include <GL/glew.h>
#include <cstdio>
#include "GLFW/glfw3.h"
#include "common/texture.hpp"
#include "common/shader.hpp"
#include "main/gameReseau/window/gr_window.hpp"
#include "main/gameReseau/gameObject/gr_gameObject.hpp"

class gr_renderer
{
private :
	std::vector<gr_gameObject*> gameObjects;
	
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // not use todo

	
	GLuint vertexArrayID;
	GLuint programID;
	GLuint matrixID;

	static void initGLEW();
	static void clearScreen();
	void drawEachObject(gr_window _gr_window) const;
	static void pollEvent();
	static void close();

public:
	static float deltaTime;
	
	gr_renderer();

	void addVertices(std::vector<glm::vec3> _vertices);
	void addUV(std::vector<glm::vec2> _uvs);

	void renderLoop(gr_window _gr_window) const;
	void clean() const;
	//	void Clean() const;
	void cleanGameObject() const;
	void clearVerticesAndUV();
	void addGameObject(gr_gameObject *_go);
};