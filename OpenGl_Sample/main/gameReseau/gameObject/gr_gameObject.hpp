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
	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix;
	glm::mat4 ModelMatrix;
	glm::mat4 MVP;
	
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
	virtual void Draw(gr_window* _windows);
	void BindTexture() const;
	void Clean() const;
	void SetColorShader(const gr_color _color) const;
	void SetUseTexture(bool _res) const;
	void ComputeMatrix(GLFWwindow* _window);
	void UseShader(GLint _shaderID);
	GLuint GetTexture() const;
	GLuint GetShader() const;
	GLuint GetTextureID() const;
	gr_transform GetTransform()const;
	void SetPosition(glm::vec3 _pos);
	void virtual SetScale(glm::vec3 _scale);


	void virtual update();
};
