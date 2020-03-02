#pragma once
#include <gl/glew.h>
#include <vector>
#include <glm/glm.hpp>

#include "main/gameReseau/color/gr_color.hpp"
#include "main/gameReseau/transform/gr_transform.hpp"

class gr_gameObject
{
protected:
	const char*  texturePath;
	
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // not used

	// shader
	GLuint programID;
	
	// buffers
	GLuint vertexBuffer;
	GLuint uvBuffer;

	
	GLuint VertexArrayID;
	GLuint MatrixID;

	
	GLuint TextureID;
	GLuint Texture = 0;
	gr_color Color;

	gr_transform transform;
	
	void LoadTexture();

	void LoadVBO();
	void LoadUVBuffer();
	void VerticesBuffer() const;
	void UvBuffer() const;
	void InitBuffer();
	void LoadShader(const char* _vertexShaderPath, const char* _fragmentShaderPath);
	void CleanBuffer() const;

public:
	gr_gameObject();
	gr_gameObject(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, const char* _texturePath = "", const char* _vertexShaderPath="", const char* _fragmentShaderPath="", gr_color _color = gr_color());
	gr_gameObject(const gr_gameObject& _gameObject);
	
	std::vector<glm::vec3> getVertices() const ;
	std::vector<glm::vec2> getUvs() const;
	std::vector<glm::vec3> getNormals() const;

	
	void MoveRight(float _speed, float _deltaTime);
	virtual void Draw();
	void BindTexture();
	void Clean() const;
	void SetColorShader(const gr_color _color);
	void SetUseTexture(bool _res);
	void ComputeMatrix(GLFWwindow* _window) const;
	void UseShader(GLint _shaderID);
	GLuint GetTexture() const;
	GLuint GetShader() const;
	GLuint GetTextureID() const;
};