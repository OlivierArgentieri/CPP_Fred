#include "gr_gameObject.hpp"

#include <glm/gtc/matrix_transform.inl>


#include "common/controls.hpp"
#include "main/gameReseau/renderer/gr_renderer.hpp"


void gr_gameObject::loadTexture()
{
	if (texturePath[0] == '\0') return;
	texture = loadDDS(texturePath); // .dds!!!
}

gr_gameObject::gr_gameObject()
{
}

gr_gameObject::gr_gameObject(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, gr_bounds _bounds, const char* _texturePath, const char* _vertexShaderPath, const char* _fragmentShaderPath, gr_color _color)
{
	transform = gr_transform(_position, _rotation, _scale);
	texturePath = _texturePath;
	loadTexture();
	loadShader(_vertexShaderPath, _fragmentShaderPath);
	color = _color;
	transform.setPosition(_position);
	gr_gameObject::setScale(_scale);
	bounds = _bounds;
}

gr_gameObject::gr_gameObject(const gr_gameObject& _gameObject)
{
	transform = gr_transform(_gameObject.transform);
	texturePath = _gameObject.texturePath;
	loadTexture();

	color = _gameObject.color;

	transform.setPosition(_gameObject.transform.position);
	gr_gameObject::setScale(_gameObject.transform.scale);
	bounds = _gameObject.bounds;
}
gr_gameObject::~gr_gameObject()
{
	glDeleteTextures(1, &texture);
}


std::vector<glm::vec3> gr_gameObject::getVertices() const
{
	return vertices;
}

std::vector<glm::vec2> gr_gameObject::getUvs() const
{
	return uvs;
}

std::vector<glm::vec3> gr_gameObject::getNormals() const
{
	return normals;
}

void gr_gameObject::moveRight(float _speed, float _deltaTime)
{
	/*
	modelMatrix = glm::translate(modelMatrix, glm::vec3(10, 0, 0));
	
	MVP = getProjectionMatrix() * getViewMatrix()* modelMatrix;
	*/
	/*
	for (glm::vec3 &vertex : vertices)
	{
		vertex.x += _speed * _deltaTime;
	}*/
}


void gr_gameObject::loadVBO()
{
	// Load it into a VBO
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
}

void gr_gameObject::loadUVBuffer()
{
	// Load UV
	glGenBuffers(1, &uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
}

void gr_gameObject::verticesBuffer() const
{
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
		0, // attribute
		3, // size
		GL_FLOAT, // type
		GL_FALSE, // normalized?
		0, // stride
		(void*)0 // array buffer offset
	);
}

void gr_gameObject::uvsBuffer() const
{
	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glVertexAttribPointer(
		1, // attribute
		2, // size
		GL_FLOAT, // type
		GL_FALSE, // normalized?
		0, // stride
		(void*)0 // array buffer offset
	);
}

void gr_gameObject::cleanBuffer() const
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &uvBuffer);
	//glDeleteTextures(1, &texture);
}

GLuint gr_gameObject::getTexture() const
{
	return texture;
}

GLuint gr_gameObject::getShader() const
{
	return programID;
}

GLuint gr_gameObject::getTextureID() const
{
	return textureID;
}

gr_transform gr_gameObject::getTransform() const
{
	return transform;
}

void gr_gameObject::setPosition(glm::vec3 _pos)
{
	transform.setPosition(_pos);
	/*for (int i = 0; i < vertices.size(); ++i)
	{
		vertices[i].x += _pos.x / 2;
		vertices[i].y += _pos.y / 2;
		vertices[i].z += _pos.z / 2;
	}*/
}

void gr_gameObject::setScale(glm::vec3 _scale)
{
	// todo in transform
	transform.setScale(_scale);
	for (int i = 0; i < vertices.size(); ++i)
	{
		vertices[i].x *= _scale.x / 2;
		vertices[i].y *= _scale.y / 2;
		vertices[i].z *= _scale.z / 2;
	}
}

void gr_gameObject::update()
{
}

void gr_gameObject::draw(gr_window* _window)
{
	if (!_window) return;

	useShader(programID);
	bindTexture();
	setUseTexture(texture != 0);
	setColorShader(color);


	computeMatrix(_window->getWindow());
	initBuffer();

	// behaviour method go
	update();

	// todo to draw methods
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	cleanBuffer();
}

void gr_gameObject::bindTexture() const
{
	if (texturePath[0] == '\0')	return;

	// enable transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Set our "myTextureSampler" sampler to use Texture Unit 0
	glUniform1i(textureID, 0);
}

void gr_gameObject::initBuffer()
{
	loadVBO();
	loadUVBuffer();

	verticesBuffer();
	uvsBuffer();
}

void gr_gameObject::loadShader(const char* _vertexShaderPath, const char* _fragmentShaderPath)
{
	if (_vertexShaderPath[0] == '\0' || _fragmentShaderPath[0] == '\0') return;
	programID = LoadShaders(_vertexShaderPath, _fragmentShaderPath);
}

void gr_gameObject::setColorShader(const gr_color _color) const
{
	GLint color = glGetUniformLocation(programID, "color");
	float editedColor[3] = {_color.r, _color.g, _color.b};
	glUniform3fv(color, 1, editedColor);;
}

void gr_gameObject::setUseTexture(const bool _res) const
{
	GLboolean color = glGetUniformLocation(programID, "isTextureLoaded");
	glUniform1i(color, _res);
}

void gr_gameObject::computeMatrix(GLFWwindow* _window)
{
	if (!_window) return;

	// Compute the MVP matrix from keyboard and mouse input
	computeMatricesFromInputs(_window); // todo 


	mvp = transform.getMVP();

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &mvp[0][0]);
}

void gr_gameObject::useShader(GLint _shaderID)
{
	// Use our shader
	glUseProgram(_shaderID);
	matrixID = glGetUniformLocation(_shaderID, "MVP");
}


void gr_gameObject::clean() const
{
	
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &vertexArrayID);
}
