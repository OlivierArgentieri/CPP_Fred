////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "Graphics.h"

#define USE_MODELOBJ 0

Graphics::Graphics()
{
	m_D3D = nullptr;
	m_Camera = nullptr;
	m_Model = nullptr;
	m_ModelObj = nullptr;
	m_ColorShader = nullptr;
	m_TextureShader = nullptr;
	m_CellShadingShader = nullptr;
}


Graphics::Graphics(const Graphics& other)
{
}


Graphics::~Graphics()
{
}


bool Graphics::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;

	m_rotationAngle = 0;
	m_RenderingMode = 0;

	// Creates the Direct3D object.
	m_D3D = new D3DLayer();
	if (!m_D3D)
	{
		return false;
	}

	// Initializes the Direct3D object.
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_DISABLED, hwnd, FULLSCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(hwnd, "Could not initialize Direct3D", "Error", MB_OK);
		return false;
	}

	// Creates the camera object.
	m_Camera = new Camera();
	if (!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
#if USE_MODELOBJ
	m_Camera->SetPosition(0.0f, +50.0f, -350.0f);
#else
	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);
#endif
	
	RenderType rdrType = eRenderNormal;
	// Create the modelObj object.
	m_ModelObj = new ModelObj(rdrType);
	if (!m_ModelObj)
	{
		return false;
	}

	// Initialize the model object.
	result = m_ModelObj->Initialize(m_D3D->GetDevice(), "Dennis30k.obj", "Dennis30k_r1.jpg");
	if (!result)
	{
		MessageBox(hwnd, "Could not initialize the model object.", "Error", MB_OK);
		return false;
	}

	// Create the model object.
	m_Model = new Model();
	if (!m_Model)
	{
		return false;
	}

	// Initialize the model object.
	result = m_Model->Initialize(m_D3D->GetDevice(), "seafloor.dds");
	if (!result)
	{
		MessageBox(hwnd, "Could not initialize the model object.", "Error", MB_OK);
		return false;
	}

	// Create the color shader object.
	m_ColorShader = new ColorShader();
	if (!m_ColorShader)
	{
		return false;
	}

	// Initialize the color shader object.
	result = m_ColorShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, "Could not initialize the color shader object.", "Error", MB_OK);
		return false;
	}

	// Create the texture shader object.
	m_TextureShader = new TextureShader();
	if (!m_TextureShader)
	{
		return false;
	}

	// Initialize the texture shader object.
	result = m_TextureShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, "Could not initialize the texture shader object.", "Error", MB_OK);
		return false;
	}

	// Create the cellShading shader object.
	m_CellShadingShader = new CellShadingShader(rdrType);
	if (!m_CellShadingShader)
	{
		return false;
	}

	// Initialize the cellShading shader object.
	result = m_CellShadingShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, "Could not initialize the Cell Shading shader object.", "Error", MB_OK);
		return false;
	}

	// Create the cellShading shader object.
	m_OutlineShader = new OutlineShader();
	if (!m_OutlineShader)
	{
		return false;
	}

	// Initialize the cellShading shader object.
	result = m_OutlineShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, "Could not initialize the Outline shader object.", "Error", MB_OK);
		return false;
	}

	return true;
}


void Graphics::Shutdown()
{
	// Release the texture shader object.
	if (m_TextureShader)
	{
		m_TextureShader->Shutdown();
		delete m_TextureShader;
		m_TextureShader = nullptr;
	}

	// Release the color shader object.
	if (m_ColorShader)
	{
		m_ColorShader->Shutdown();
		delete m_ColorShader;
		m_ColorShader = nullptr;
	}

	// Release the color shader object.
	if (m_ColorShader)
	{
		m_ColorShader->Shutdown();
		delete m_ColorShader;
		m_ColorShader = nullptr;
	}

	// Release the Cell Shading shader object.
	if (m_CellShadingShader)
	{
		m_CellShadingShader->Shutdown();
		delete m_CellShadingShader;
		m_CellShadingShader = nullptr;
	}

	// Release the Cell Shading shader object.
	if (m_OutlineShader)
	{
		m_OutlineShader->Shutdown();
		delete m_OutlineShader;
		m_OutlineShader = nullptr;
	}


	// Release the model object.
	if (m_Model)
	{
		m_Model->Shutdown();
		delete m_Model;
		m_Model = nullptr;
	}

	// Release the modelObj object.
	if (m_ModelObj)
	{
		m_ModelObj->Shutdown();
		delete m_ModelObj;
		m_ModelObj = nullptr;
	}


	// Release the camera object.
	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = nullptr;
	}

	if (m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = nullptr;
	}

	return;
}


bool Graphics::Tick()
{
	return Render();
}


bool Graphics::Render()
{
	DirectX::XMMATRIX viewMatrix, projectionMatrix, worldMatrix, worldInverse;

	// Clear the buffers to begin the scene.
	m_D3D->BeginScene(0.8f, 0.8f, 0.8f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->Render();

	// Get the world, view, and projection matrices from the camera and d3d objects.
	m_Camera->GetViewMatrix(viewMatrix);
	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);

	worldInverse = DirectX::XMMatrixInverse(nullptr, worldMatrix);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	m_Model->Render(m_D3D->GetDeviceContext());
	switch (m_RenderingMode)
	{
		// Render the model using the color shader.
	case 0:
		if (!m_ColorShader->Render(m_D3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix))
			return false;
		break;

	default:
		// Render the model using the texture shader.
		if (!m_TextureShader->Render(m_D3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, m_Model->GetTexture()))
			return false;
		break;
	}

	// rotate only the model, each frame by a little more
#if USE_MODELOBJ
	float pitch = 0.0f;
	float yaw = m_rotationAngle * 0.0174532925f * 0.005f;
	float roll = 0.0f;
	m_rotationAngle++;
	if (m_rotationAngle == 72000)
		m_rotationAngle = 0;
	DirectX::XMMATRIX rotationMatrix = DirectX::XMMatrixRotationRollPitchYaw(pitch, yaw, roll);
	DirectX::XMMATRIX rotatedObjMatrix = DirectX::XMMatrixMultiply(worldMatrix, rotationMatrix);

	

	m_ModelObj->Render(m_D3D->GetDeviceContext() );

	/*
	m_D3D->RasterStateCCW();
	if (!m_OutlineShader->Render(m_D3D->GetDeviceContext(), m_ModelObj->GetIndexCount(), rotatedObjMatrix, viewMatrix, projectionMatrix, worldInverse, m_ModelObj->GetTexture()))
		return false;

	m_D3D->RasterStateCW();
	*/
	if (!m_CellShadingShader->Render(m_D3D->GetDeviceContext(), m_ModelObj->GetIndexCount(), rotatedObjMatrix, viewMatrix, projectionMatrix, worldInverse, m_ModelObj->GetTexture()))
		return false;
	
#endif



	// Present the rendered scene to the screen.
	m_D3D->EndScene();

	return true;
}