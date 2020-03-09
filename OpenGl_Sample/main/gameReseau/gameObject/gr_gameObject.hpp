#pragma once
#include <gl/glew.h>
#include <vector>
#include <glm/glm.hpp>

#include "main/gameReseau/color/gr_color.hpp"
#include "main/gameReseau/transform/gr_transform.hpp"
#include "main/gameReseau/window/gr_window.hpp"

class gr_gameObject
{

private :
	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 modelMatrix;
	glm::mat4 mvp;
	
protected:
	const char*  texturePath;
	const char*  vertexShaderPath;
	const char*  fragmentShaderPath;
	
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // not used

	// shader
	GLuint programID;
	
	// buffers
	GLuint vertexBuffer;
	GLuint uvBuffer;

	GLuint vertexArrayID;
	GLuint matrixID;

	GLuint textureID;
	GLuint texture = 0;
	gr_color color;

	gr_transform transform;
	
	void loadTexture();

	void loadVBO();
	void loadUVBuffer();
	void verticesBuffer() const;
	void uvsBuffer() const;
	void initBuffer();
	void loadShader(const char* _vertexShaderPath, const char* _fragmentShaderPath);
	void cleanBuffer() const;

public:
	gr_gameObject();
	gr_gameObject(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, const char* _texturePath = "", const char* _vertexShaderPath="", const char* _fragmentShaderPath="", gr_color _color = gr_color());
	gr_gameObject(const gr_gameObject& _gameObject);
	
	std::vector<glm::vec3> getVertices() const ;
	std::vector<glm::vec2> getUvs() const;
	std::vector<glm::vec3> getNormals() const;

	
	void moveRight(float _speed, float _deltaTime);
	virtual void draw(gr_window* _windows);
	void bindTexture() const;
	void clean() const;
	void setColorShader(const gr_color _color) const;
	void setUseTexture(bool _res) const;
	void computeMatrix(GLFWwindow* _window);
	void useShader(GLint _shaderID);
	GLuint getTexture() const;
	GLuint getShader() const;
	GLuint getTextureID() const;
	gr_transform getTransform()const;
	void setPosition(glm::vec3 _pos);
	void virtual setScale(glm::vec3 _scale);

	void virtual update();
};
