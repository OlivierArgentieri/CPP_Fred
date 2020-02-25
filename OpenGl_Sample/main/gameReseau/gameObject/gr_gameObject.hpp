#pragma once
#include <gl/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include "main/gameReseau/transform/gr_transform.hpp"

class gr_gameObject
{
protected:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // not used
	// buffers
	// 
	GLuint vertexBuffer;
	GLuint uvBuffer;

	GLuint Texture; // todo

	gr_transform transform;
	
	void LoadTexture();
	void LoadVBO();
	void LoadUVBuffer();
	void VerticesBuffer() const;
	void UvBuffer() const;
	void InitBuffer();
	
public:

	gr_gameObject();
	gr_gameObject(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
	gr_gameObject(const gr_gameObject& _gameObject);
	
	std::vector<glm::vec3> getVertices() const ;
	std::vector<glm::vec2> getUvs() const;
	std::vector<glm::vec3> getNormals() const;


	void MoveRight(float _speed, float _deltaTime);
	void Draw();
	void CleanBuffer() const;


};