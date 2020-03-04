#include "gr_gameObject.hpp"

#include <glm/gtc/matrix_transform.inl>


#include "common/controls.hpp"
#include "main/gameReseau/renderer/gr_renderer.hpp"


void gr_gameObject::LoadTexture()
{
	if (texturePath[0] == '\0') return;
	Texture = loadDDS(texturePath); // .dds!!!
}

gr_gameObject::gr_gameObject()
{
}

gr_gameObject::gr_gameObject(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, const char* _texturePath, const char* _vertexShaderPath, const char* _fragmentShaderPath, gr_color _color)
{
	transform = gr_transform(_position, _rotation, _scale);
	texturePath = _texturePath;
	LoadTexture();
	LoadShader(_vertexShaderPath, _fragmentShaderPath);
	Color = _color;
	SetPosition(_position);
	gr_gameObject::SetScale(_scale);
}

gr_gameObject::gr_gameObject(const gr_gameObject& _gameObject)
{
	transform = gr_transform(_gameObject.transform);
	texturePath = _gameObject.texturePath;
	LoadTexture();
	
	Color = _gameObject.Color;

	SetPosition(_gameObject.transform.position);
	gr_gameObject::SetScale(_gameObject.transform.scale);
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

void gr_gameObject::MoveRight(float _speed, float _deltaTime)
{
	/*
	ModelMatrix = glm::translate(ModelMatrix, glm::vec3(10, 0, 0));
	
	MVP = getProjectionMatrix() * getViewMatrix()* ModelMatrix;
	*/
	/*
	for (glm::vec3 &vertex : vertices)
	{
		vertex.x += _speed * _deltaTime;
	}*/
}


void gr_gameObject::LoadVBO()
{
	// Load it into a VBO
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
}

void gr_gameObject::LoadUVBuffer()
{
	// Load UV
	glGenBuffers(1, &uvBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
}

void gr_gameObject::VerticesBuffer() const
{
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
}

void gr_gameObject::UvBuffer() const
{
	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);
}

void gr_gameObject::CleanBuffer() const
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &uvBuffer);
	//glDeleteTextures(1, &Texture);
}

GLuint gr_gameObject::GetTexture() const
{
	return Texture;
}

GLuint gr_gameObject::GetShader() const
{
	return programID;
}

GLuint gr_gameObject::GetTextureID() const
{
	return TextureID;
}

gr_transform gr_gameObject::GetTransform() const
{
	return transform;
}

void gr_gameObject::SetPosition(glm::vec3 _pos)
{
	transform.SetPosition(_pos);
}

void gr_gameObject::SetScale(glm::vec3 _scale)
{
	// todo in transform
	transform.SetScale(_scale);
	for	(int i = 0; i < vertices.size() ; ++i)
	{
		vertices[i].x *= _scale.x/2;
		vertices[i].y *= _scale.y/2;
		vertices[i].z *= _scale.z/2;
	}
}

void gr_gameObject::update()
{
	
}

void gr_gameObject::Draw(gr_window* _window)
{
	if (!_window) return;

	UseShader(programID);
	BindTexture();
	SetUseTexture(Texture != 0);
	SetColorShader(Color);

	ComputeMatrix(_window->GetWindow());
	InitBuffer();

	// behaviour method go
	update();
	
	// todo to draw methods
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	
	CleanBuffer();
}

void gr_gameObject::BindTexture() const
{
	if (texturePath[0] == '\0')
	{
		// set active texture to empty slot
		return;
	}
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture);

	
	// Set our "myTextureSampler" sampler to use Texture Unit 0
	glUniform1i(TextureID, 0);
}

void gr_gameObject::InitBuffer()
{
	LoadVBO();
	LoadUVBuffer();

	VerticesBuffer();
	UvBuffer();
}

void gr_gameObject::LoadShader(const char* _vertexShaderPath, const char* _fragmentShaderPath)
{
	if (_vertexShaderPath[0] == '\0' || _fragmentShaderPath[0] == '\0') return;
	programID = LoadShaders(_vertexShaderPath, _fragmentShaderPath);
}

void gr_gameObject::SetColorShader(const gr_color _color) const
{
	GLint color = glGetUniformLocation(programID, "color");
	float editedColor[3] = {_color.r, _color.g, _color.b};
	glUniform3fv(color, 1, editedColor);;
}

void gr_gameObject::SetUseTexture(const bool _res) const
{
	GLboolean color = glGetUniformLocation(programID, "isTextureLoaded");
	glUniform1i(color, _res);
}

void gr_gameObject::ComputeMatrix(GLFWwindow* _window)
{
	if (!_window) return;

	// Compute the MVP matrix from keyboard and mouse input
	computeMatricesFromInputs(_window); // todo 

	
	MVP = transform.GetMVP();

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
}

void gr_gameObject::UseShader(GLint _shaderID)
{
	// Use our shader
	glUseProgram(_shaderID); // todo in game object
	MatrixID = glGetUniformLocation(_shaderID, "MVP");
}


void gr_gameObject::Clean() const
{
	glDeleteTextures(1, &Texture);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
}
