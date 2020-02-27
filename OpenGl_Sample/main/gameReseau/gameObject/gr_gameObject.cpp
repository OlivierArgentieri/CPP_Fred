#include "gr_gameObject.hpp"
#include "main/gameReseau/renderer/gr_renderer.hpp"
#include "common/objloader.hpp"


void gr_gameObject::LoadTexture()
{
	// Load the texture
	//Texture = loadDDS("uvmap.DDS"); // todo test
	Texture = loadDDS(texturePath); // .dds!!!
}

gr_gameObject::gr_gameObject()
{
}

gr_gameObject::gr_gameObject(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, const char* _texturePath)
{
	transform = gr_transform(_position, _rotation, _scale);
	texturePath = _texturePath;
	LoadTexture();

}

gr_gameObject::gr_gameObject(const gr_gameObject& _gameObject)
{
	transform = gr_transform(_gameObject.transform);
	texturePath = _gameObject.texturePath;
	LoadTexture();

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
	for (glm::vec3 &vertex : vertices)
	{
		vertex.x += _speed * _deltaTime;
	}
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

GLuint gr_gameObject::GetTextureID() const
{
	return TextureID;
}
void gr_gameObject::Draw()
{
	InitBuffer();
	BindTexture();
	// Draw the triangle !

	glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	
	//glDisableVertexAttribArray(0);
	//glDisableVertexAttribArray(1);
	CleanBuffer();
}

void gr_gameObject::BindTexture() // todo
{
	
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

void gr_gameObject::Clean() const
{
	glDeleteTextures(1, &Texture);
}
