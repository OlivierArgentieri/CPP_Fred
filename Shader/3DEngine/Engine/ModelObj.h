////////////////////////////////////////////////////////////////////////////////
// Filename: ModelObj.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _MODELOBJCLASS_H_
#define _MODELOBJCLASS_H_


//////////////
// INCLUDES //
//////////////
#include <d3d11.h>

#include "Texture.h"
#include <list>
#include <vector>


////////////////////////////////////////////////////////////////////////////////
// Class name: ModelObj
////////////////////////////////////////////////////////////////////////////////
class ModelObj
{
private:
	struct VertexTypeWithColor
	{
		DirectX::XMFLOAT3 position;
		DirectX::XMFLOAT2 texture;
		DirectX::XMFLOAT4 color;
	};

	struct VertexTypeWithNormal
	{
		DirectX::XMFLOAT3 position;
		DirectX::XMFLOAT2 texture;
		DirectX::XMFLOAT3 normal;
		DirectX::XMFLOAT4 color;
	};

	struct FaceDesc
	{
		int vertexIdx0;
		int vertexUVIdx0;
		int vertexNormalIdx0;
		int vertexIdx1;
		int vertexUVIdx1;
		int vertexNormalIdx1;
		int vertexIdx2;
		int vertexUVIdx2;
		int vertexNormalIdx2;
	};


public:
	ModelObj(RenderType _rdrType);
	ModelObj(const ModelObj&);
	~ModelObj();

	bool Initialize(ID3D11Device *_device, char *_objFilename, char *_textureFilename);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();

	ID3D11ShaderResourceView* GetTexture();

private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);
	bool LoadTexture(ID3D11Device*_device, char*_filename);
	bool LoadObj(ID3D11Device *_device, char *_filename);
	void ReleaseTexture();
	void addVertex(float x, float y, float z);
	void addNormal(float x, float y, float z);
	void addUVs(float u, float v);
	void addFaces(int vertexIdx0, int vertexUVIdx0, int vertexNormalIdx0, int vertexIdx1, int vertexUVIdx1, int vertexNormalIdx1, int vertexIdx2, int vertexUVIdx2, int vertexNormalIdx2);

private:
	RenderType m_renderType;
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	Texture* m_Texture;
	std::vector<DirectX::XMFLOAT3> m_verticesList;
	std::vector<DirectX::XMFLOAT3> m_normalsList;
	std::vector<DirectX::XMFLOAT2> m_uvsList;
	std::list<FaceDesc> m_facesList;
};

#endif