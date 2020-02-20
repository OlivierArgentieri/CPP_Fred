////////////////////////////////////////////////////////////////////////////////
// Filename: CellShadingShader.cpp
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "CellShadingShader.h"
#include "System.h"


CellShadingShader::CellShadingShader(RenderType _rdrType)
{
	m_vertexShader = 0;
	m_pixelShader = 0;
	m_layout = 0;
	m_matrixBuffer = 0;
	m_sampleState = 0;
	m_renderingType = _rdrType;
}

CellShadingShader::CellShadingShader(const CellShadingShader& other)
{
}

CellShadingShader::~CellShadingShader()
{
}

bool CellShadingShader::Initialize(ID3D11Device *_device, HWND _hWnd)
{
	bool result;

	// Initialize the vertex and pixel shaders.
	switch (m_renderingType)
	{
		case eRenderColor:
			result = InitializeShader(_device, _hWnd, "cellshading1.vs", "cellshading1.ps"); // Color 
			break;

		case eRenderNormal:
			result = InitializeShader(_device, _hWnd, "cellshading2.vs", "cellshading2.ps"); // Color 
			break;
		default:
			break;
	}

	if(!result)
	{
		return false;
	}

	return true;
}


void CellShadingShader::Shutdown()
{
	// Shutdown the vertex and pixel shaders as well as the related objects.
	ShutdownShader();

	return;
}


bool CellShadingShader::InitializeShader(ID3D11Device *_device, HWND _hWnd, char *_vsFilename, char *_psFilename)
{
	HRESULT result;
	ID3D10Blob* errorMessage;
	ID3D10Blob* vertexShaderBuffer;
	ID3D10Blob* pixelShaderBuffer;
	D3D11_INPUT_ELEMENT_DESC polygonLayout[5];
	unsigned int numElements;
	D3D11_BUFFER_DESC matrixBufferDesc;
	D3D11_SAMPLER_DESC samplerDesc;

	char fullVSName[1024];
	char fullPSName[1024];
	sprintf_s(fullVSName, "%s%s", System::Get()->GetDataDirectory(), _vsFilename);
	sprintf_s(fullPSName, "%s%s", System::Get()->GetDataDirectory(), _psFilename);

	// Initialize the pointers this function will use to null.
	errorMessage = 0;
	vertexShaderBuffer = 0;
	pixelShaderBuffer = 0;

    // Compile the vertex shader code.
	result = D3DX11CompileFromFile(fullVSName, NULL, NULL, "CellShadingVertexShader", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL, &vertexShaderBuffer, &errorMessage, NULL);
	if(FAILED(result))
	{
		// If the shader failed to compile it should have writen something to the error message.
		if(errorMessage)
		{
			OutputShaderErrorMessage(errorMessage, _hWnd, fullVSName);
		}
		// If there was  nothing in the error message then it simply could not find the shader file itself.
		else
		{
			MessageBox(_hWnd, fullVSName, "Missing Shader File", MB_OK);
		}

		return false;
	}

    // Compile the pixel shader code.
	result = D3DX11CompileFromFile(fullPSName, NULL, NULL, "CellShadingPixelShader", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL, &pixelShaderBuffer, &errorMessage, NULL);
	if(FAILED(result))
	{
		// If the shader failed to compile it should have writen something to the error message.
		if(errorMessage)
		{
			OutputShaderErrorMessage(errorMessage, _hWnd, fullPSName);
		}
		// If there was nothing in the error message then it simply could not find the file itself.
		else
		{
			MessageBox(_hWnd, fullPSName, "Missing Shader File", MB_OK);
		}

		return false;
	}

    // Create the vertex shader from the buffer.
    result = _device->CreateVertexShader(vertexShaderBuffer->GetBufferPointer(), vertexShaderBuffer->GetBufferSize(), NULL, &m_vertexShader);
	if(FAILED(result))
	{
		return false;
	}

    // Create the pixel shader from the buffer.
    result = _device->CreatePixelShader(pixelShaderBuffer->GetBufferPointer(), pixelShaderBuffer->GetBufferSize(), NULL, &m_pixelShader);
	if(FAILED(result))
	{
		return false;
	}

	// Create the vertex input layout description.
	// This setup needs to match the VertexType stucture in the ModelClass and in the shader.
	int layoutId = 0;
	polygonLayout[layoutId].SemanticName = "POSITION";
	polygonLayout[layoutId].SemanticIndex = 0;
	polygonLayout[layoutId].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	polygonLayout[layoutId].InputSlot = 0;
	polygonLayout[layoutId].AlignedByteOffset = 0;
	polygonLayout[layoutId].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[layoutId].InstanceDataStepRate = 0;

	layoutId++;
	if( m_renderingType == eRenderNormal  )
	{ 
		polygonLayout[layoutId].SemanticName = "NORMAL";
		polygonLayout[layoutId].SemanticIndex = 0;
		polygonLayout[layoutId].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		polygonLayout[layoutId].InputSlot = 0;
		polygonLayout[layoutId].AlignedByteOffset = 0; // D3D11_APPEND_ALIGNED_ELEMENT;
		polygonLayout[layoutId].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		polygonLayout[layoutId].InstanceDataStepRate = 0;
		layoutId++;
	}
	

	{
		polygonLayout[layoutId].SemanticName = "TEXCOORD";
		polygonLayout[layoutId].SemanticIndex = 0;
		polygonLayout[layoutId].Format = DXGI_FORMAT_R32G32_FLOAT;
		polygonLayout[layoutId].InputSlot = 0;
		polygonLayout[layoutId].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
		polygonLayout[layoutId].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		polygonLayout[layoutId].InstanceDataStepRate = 0;
		layoutId++;
	}

	{
		polygonLayout[layoutId].SemanticName = "COLOR";
		polygonLayout[layoutId].SemanticIndex = 0;
		polygonLayout[layoutId].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		polygonLayout[layoutId].InputSlot = 0;
		polygonLayout[layoutId].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
		polygonLayout[layoutId].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		polygonLayout[layoutId].InstanceDataStepRate = 0;
	}

	// Get a count of the elements in the layout.
	numElements = ++layoutId; // sizeof(polygonLayout) / sizeof(polygonLayout[0]);

	// Create the vertex input layout.
	result = _device->CreateInputLayout(polygonLayout, numElements, vertexShaderBuffer->GetBufferPointer(), 
									   vertexShaderBuffer->GetBufferSize(), &m_layout);
	if(FAILED(result))
	{
		return false;
	}

	// Release the vertex shader buffer and pixel shader buffer since they are no longer needed.
	vertexShaderBuffer->Release();
	vertexShaderBuffer = 0;

	pixelShaderBuffer->Release();
	pixelShaderBuffer = 0;

    // Setup the description of the dynamic matrix constant buffer that is in the vertex shader.
    matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(MatrixBufferType);
    matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	// Create the constant buffer pointer so we can access the vertex shader constant buffer from within this class.
	result = _device->CreateBuffer(&matrixBufferDesc, NULL, &m_matrixBuffer);
	if(FAILED(result))
	{
		return false;
	}


	// Create a texture sampler state description.
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.MipLODBias = 0.0f;
	samplerDesc.MaxAnisotropy = 1;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	samplerDesc.BorderColor[0] = 0;
	samplerDesc.BorderColor[1] = 0;
	samplerDesc.BorderColor[2] = 0;
	samplerDesc.BorderColor[3] = 0;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

	// Create the texture sampler state.
	result = _device->CreateSamplerState(&samplerDesc, &m_sampleState);
	if (FAILED(result))
	{
		return false;
	}


	return true;
}


void CellShadingShader::ShutdownShader()
{
	// Release the matrix constant buffer.
	if(m_matrixBuffer)
	{
		m_matrixBuffer->Release();
		m_matrixBuffer = 0;
	}

	// Release the layout.
	if(m_layout)
	{
		m_layout->Release();
		m_layout = 0;
	}

	// Release the pixel shader.
	if(m_pixelShader)
	{
		m_pixelShader->Release();
		m_pixelShader = 0;
	}

	// Release the vertex shader.
	if(m_vertexShader)
	{
		m_vertexShader->Release();
		m_vertexShader = 0;
	}

	return;
}


void CellShadingShader::OutputShaderErrorMessage(ID3D10Blob* errorMessage, HWND hwnd, char* shaderFilename)
{
	char* compileErrors;
	ofstream fout;

	// Get a pointer to the error message text buffer.
	compileErrors = (char*)(errorMessage->GetBufferPointer());

	// Get the length of the message.
	size_t bufferSize = errorMessage->GetBufferSize();

	// Open a file to write the error message to.
	fout.open("shader-error.txt");

	// Write out the error message.
	for(size_t i=0; i<bufferSize; i++)
	{
		fout << compileErrors[i];
	}

	// Close the file.
	fout.close();

	// Release the error message.
	errorMessage->Release();
	errorMessage = 0;

	// Pop a message up on the screen to notify the user to check the text file for compile errors.
	MessageBox(hwnd, "Error compiling shader.  Check shader-error.txt for message.", shaderFilename, MB_OK);

	return;
}


bool CellShadingShader::SetShaderParameters(
		ID3D11DeviceContext* deviceContext, 
		DirectX::XMMATRIX worldMatrix, 
		DirectX::XMMATRIX viewMatrix,
		DirectX::XMMATRIX projectionMatrix, 
		DirectX::XMMATRIX worldInverse,
		ID3D11ShaderResourceView* _texture)
{
	HRESULT result;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	MatrixBufferType* dataPtr;
	unsigned int bufferNumber;

	// Transpose the matrices to prepare them for the shader.
	worldMatrix = DirectX::XMMatrixTranspose(worldMatrix);
	viewMatrix = DirectX::XMMatrixTranspose(viewMatrix);
	projectionMatrix = DirectX::XMMatrixTranspose(projectionMatrix);

	// The transpose of the inverse of the world transformation, used for transforming the vertex's normal
	//worldInverseTranspose = DirectX::XMMatrixTranspose(worldInverseTranspose);


	// Lock the constant buffer so it can be written to.
	result = deviceContext->Map(m_matrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
	{
		return false;
	}

	// Get a pointer to the data in the constant buffer.
	dataPtr = (MatrixBufferType*)mappedResource.pData;

	// Copy the matrices into the constant buffer.
	dataPtr->world = worldMatrix;
	dataPtr->view = viewMatrix;
	dataPtr->projection = projectionMatrix;
	dataPtr->worldInverse = worldInverse;

	// Unlock the constant buffer.
	deviceContext->Unmap(m_matrixBuffer, 0);

	// Set the position of the constant buffer in the vertex shader.
	bufferNumber = 0;

	// Finaly set the constant buffer in the vertex shader with the updated values.
	deviceContext->VSSetConstantBuffers(bufferNumber, 1, &m_matrixBuffer);

	// Set shader texture resource in the pixel shader.
	deviceContext->PSSetShaderResources(0, 1, &_texture);


	return true;
}




bool CellShadingShader::Render(ID3D11DeviceContext* deviceContext, int indexCount, DirectX::XMMATRIX worldMatrix, DirectX::XMMATRIX viewMatrix,
	DirectX::XMMATRIX projectionMatrix, DirectX::XMMATRIX worldInverse,  ID3D11ShaderResourceView* _texture)
{
	// Set the shader parameters that it will use for rendering.
	bool result = SetShaderParameters(deviceContext, worldMatrix, viewMatrix, projectionMatrix, worldInverse, _texture);
	if (!result)
	{
		return false;
	}

	// Now render the prepared buffers with the shader.
	RenderShader(deviceContext, indexCount);

	return true;
}




void CellShadingShader::RenderShader(ID3D11DeviceContext* deviceContext, int indexCount)
{
	// Set the vertex input layout.
	deviceContext->IASetInputLayout(m_layout);

    // Set the vertex and pixel shaders that will be used to render this triangle.
    deviceContext->VSSetShader(m_vertexShader, NULL, 0);
    deviceContext->PSSetShader(m_pixelShader, NULL, 0);

	// Render the triangles
	deviceContext->DrawIndexed(indexCount, 0, 0);
}

