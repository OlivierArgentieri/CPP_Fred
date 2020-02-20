////////////////////////////////////////////////////////////////////////////////
// Filename: ModelObj.cpp
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"


#include "ModelObj.h"
#include "System.h"


ModelObj::ModelObj(RenderType _rdrType)
{
	m_vertexBuffer = nullptr;
	m_indexBuffer = nullptr;
	m_Texture = nullptr;
	m_renderType = _rdrType;
}


ModelObj::ModelObj(const ModelObj& other)
{
}


ModelObj::~ModelObj()
{
}


bool ModelObj::Initialize(ID3D11Device *_device, char *_objFilename, char *_textureFilename)
{
	bool result;

	// Load the mesh for this model.
	char fullObjeName[1024];
	sprintf_s(fullObjeName, "%s%s", System::Get()->GetDataDirectory(), _objFilename);
	result = LoadObj(_device, fullObjeName);
	if (!result)
	{
		return false;
	}

	// Load the texture for this model.
	char fullTextureName[1024];
	sprintf_s(fullTextureName, "%s%s", System::Get()->GetDataDirectory(), _textureFilename);
	result = LoadTexture(_device, fullTextureName);
	if (!result)
	{
		return false;
	}


	// Then Initialize the vertex and index buffers.
	result = InitializeBuffers(_device);
	if(!result)
	{
		return false;
	}


	return true;
}


void ModelObj::Shutdown()
{
	// Release the model texture.
	ReleaseTexture();

	// Shutdown the vertex and index buffers.
	ShutdownBuffers();

	return;
}


void ModelObj::Render(ID3D11DeviceContext *_deviceContext)
{
	// Put the vertex and index buffers on the graphics pipeline to prepare them for drawing.
	RenderBuffers(_deviceContext);

	return;
}


int ModelObj::GetIndexCount()
{
	return m_indexCount;
}

ID3D11ShaderResourceView* ModelObj::GetTexture()
{
	return m_Texture->GetTexture();
}

bool ModelObj::InitializeBuffers(ID3D11Device *_device)
{
	VertexTypeWithNormal* verticesWithNormal;
	VertexTypeWithColor* verticesWithColor;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
    D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;


	// Naive approach, do not care about vertex count (no vertex sharing here !)

	// Set the number of vertices in the vertex array.
	m_vertexCount = (int)m_facesList.size() * 3; //  m_verticesList.size();

	// Set the number of indices in the index array.
	m_indexCount = (int)m_facesList.size() * 3;

	// Create the vertex array.
	verticesWithNormal = new VertexTypeWithNormal[m_vertexCount];
	verticesWithColor = new VertexTypeWithColor[m_vertexCount];

	// Create the index array.
	indices = new unsigned long[m_indexCount];
	if(!indices)
	{
		return false;
	}


	// Load the vertex array with data.
	int curVertex = 0;
	DirectX::XMFLOAT2 uv(0.0f, 0.0f);
	DirectX::XMFLOAT4 color(0.5f, 0.5f, 0.5f, 0.5f);
//	DirectX::XMFLOAT4 color(0.0f, 0.0f, 0.0f, 0.0f);  // NOIR alors que la couleur n'est pas noir au final!

	for(FaceDesc face : m_facesList)
	{
		DirectX::XMFLOAT3 pos0 = m_verticesList[face.vertexIdx0];
		DirectX::XMFLOAT3 pos1 = m_verticesList[face.vertexIdx1];
		DirectX::XMFLOAT3 pos2 = m_verticesList[face.vertexIdx2];

		DirectX::XMFLOAT3 normal0 = m_normalsList[face.vertexNormalIdx0];
		DirectX::XMFLOAT3 normal1 = m_normalsList[face.vertexNormalIdx1];
		DirectX::XMFLOAT3 normal2 = m_normalsList[face.vertexNormalIdx2];

		DirectX::XMFLOAT2 uv0 = m_uvsList[face.vertexUVIdx0];
		DirectX::XMFLOAT2 uv1 = m_uvsList[face.vertexUVIdx1];
		DirectX::XMFLOAT2 uv2 = m_uvsList[face.vertexUVIdx2];

		// First triangle
		verticesWithNormal[curVertex].position = pos0;
		verticesWithNormal[curVertex].normal = normal0;
		verticesWithNormal[curVertex].texture = uv0;
		verticesWithNormal[curVertex].color = color;

		verticesWithColor[curVertex].position = pos0;
		verticesWithColor[curVertex].texture = uv0;
		verticesWithColor[curVertex].color = color;

		indices[curVertex] = curVertex;
		curVertex++;

		verticesWithNormal[curVertex].position = pos1;
		verticesWithNormal[curVertex].normal = normal1;
		verticesWithNormal[curVertex].texture = uv1;
		verticesWithNormal[curVertex].color = color;

		verticesWithColor[curVertex].position = pos1;
		verticesWithColor[curVertex].texture = uv1;
		verticesWithColor[curVertex].color = color;

		indices[curVertex] = curVertex;
		curVertex++;

		verticesWithNormal[curVertex].position = pos2;
		verticesWithNormal[curVertex].normal = normal2;
		verticesWithNormal[curVertex].texture = uv2;
		verticesWithNormal[curVertex].color = color;

		verticesWithColor[curVertex].position = pos2;
		verticesWithColor[curVertex].color = color;
		verticesWithColor[curVertex].texture = uv2;

		indices[curVertex] = curVertex;
		curVertex++;
		
	}

	// Set up the description of the static vertex buffer.
    vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	switch (m_renderType)
	{
		case eRenderColor: 
			vertexBufferDesc.ByteWidth = sizeof(VertexTypeWithColor) * m_vertexCount; 
			// Give the subresource structure a pointer to the vertex data.
			vertexData.pSysMem = verticesWithColor;
			break;

		case eRenderNormal: 
			vertexBufferDesc.ByteWidth = sizeof(VertexTypeWithNormal) * m_vertexCount;
			// Give the subresource structure a pointer to the vertex data.
			vertexData.pSysMem = verticesWithNormal;
			break;
	}
    
    vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    vertexBufferDesc.CPUAccessFlags = 0;
    vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// Now create the vertex buffer.
    result = _device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if(FAILED(result))
	{
		return false;
	}

	// Set up the description of the static index buffer.
    indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
    indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
    indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    indexBufferDesc.CPUAccessFlags = 0;
    indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// Give the subresource structure a pointer to the index data.
    indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// Create the index buffer.
	result = _device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if(FAILED(result))
	{
		return false;
	}

	// Release the arrays now that the vertex and index buffers have been created and loaded.
	delete[] verticesWithNormal;
	verticesWithNormal = 0;

	delete [] verticesWithColor;
	verticesWithColor = 0;

	delete [] indices;
	indices = 0;

	return true;
}


void ModelObj::ShutdownBuffers()
{
	// Release the index buffer.
	if(m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}

	// Release the vertex buffer.
	if(m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	return;
}


void ModelObj::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;


	// Set vertex buffer stride and offset.
	stride = sizeof(VertexTypeWithNormal); 
	offset = 0;
    
	// Set the vertex buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);

    // Set the index buffer to active in the input assembler so it can be rendered.
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);

    // Set the type of primitive that should be rendered from this vertex buffer, in this case triangles.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	return;
}

bool ModelObj::LoadTexture(ID3D11Device *_device, char *_filename)
{
	bool result;

	// Create the texture object.
	m_Texture = new Texture;
	if (!m_Texture)
	{
		return false;
	}

	// Initialize the texture object.
	result = m_Texture->Initialize(_device, _filename);
	if (!result)
	{
		return false;
	}

	return true;
}

void ModelObj::ReleaseTexture()
{
	// Release the texture object.
	if (m_Texture)
	{
		m_Texture->Shutdown();
		delete m_Texture;
		m_Texture = 0;
	}

	return;
}

void ModelObj::addVertex(float x, float y, float z)
{
	m_verticesList.push_back(DirectX::XMFLOAT3(x, y, z));
}

void ModelObj::addNormal(float x, float y, float z)
{
	m_normalsList.push_back( DirectX::XMFLOAT3(x, y, z));
}

void ModelObj::addUVs(float u, float v)
{
	m_uvsList.push_back(DirectX::XMFLOAT2(u, v));
}


void ModelObj::addFaces(int vertexIdx0, int vertexUVIdx0, int vertexNormalIdx0, int vertexIdx1, int vertexUVIdx1, int vertexNormalIdx1, int vertexIdx2, int vertexUVIdx2, int vertexNormalIdx2 )
{
	FaceDesc face;

	face.vertexIdx0 = vertexIdx0;
	face.vertexUVIdx0 = vertexUVIdx0;
	face.vertexNormalIdx0 = vertexNormalIdx0;

	face.vertexIdx1 = vertexIdx1;
	face.vertexUVIdx1 = vertexUVIdx1;
	face.vertexNormalIdx1 = vertexNormalIdx1;

	face.vertexIdx2 = vertexIdx2;
	face.vertexUVIdx2 = vertexUVIdx2;
	face.vertexNormalIdx2 = vertexNormalIdx2;

	m_facesList.push_back(face);
}

bool ModelObj::LoadObj(ID3D11Device *_device, char *_filename)
{
	FILE *fp;
	
	m_vertexCount = 0;
	errno_t err = fopen_s(&fp, _filename, "r");
	if (err!=0)
		return false;

	char line[2048];
	float x, y, z, u, v;
	int iv0, iuv0, in0, iv1, iuv1, in1, iv2, iuv2, in2;

	while (fgets(line, 2048, fp) != nullptr)
	{
		// parse the line
		if (strlen(line) < 5)
			continue;

		if (sscanf_s(line, "v %f %f %f", &x, &y, &z) == 3)
		{
			addVertex(x, y, z);
		}

		if (sscanf_s(line, "vn %f %f %f", &x, &y, &z) == 3)
		{
			addNormal(x, y, z);
		}

		if (sscanf_s(line, "vt %f %f %f", &u, &v, &z) == 3)
		{
			addUVs(u, v);
		}

		if (sscanf_s(line, "f %i/%i/%i %i/%i/%i %i/%i/%i", &iv0, &iuv0, &in0, &iv1, &iuv1, &in1, &iv2, &iuv2, &in2 ) == 9)
		{
			// we're 0 based ! everything minus 1
			iv0--;
			iuv0--;
			in0--;
			iv1--;
			iuv1--;
			in1--;
			iv2--;
			iuv2--;
			in2--;

			addFaces( iv0, iuv0, in0, iv1, iuv1, in1, iv2, iuv2, in2);
		}
	}

	fclose(fp);




	return true; // we're done
}