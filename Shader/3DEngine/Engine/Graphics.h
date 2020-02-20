////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


//////////////
// INCLUDES //
//////////////
#include "D3DLayer.h"
#include "Camera.h"
#include "Model.h"
#include "ModelObj.h"
#include "ColorShader.h"
#include "TextureShader.h"
#include "OutlineShader.h"
#include "CellShadingShader.h"

/////////////
// GLOBALS //
/////////////
const bool FULLSCREEN = false;
const bool VSYNC_ENABLED = true;
const bool VSYNC_DISABLED = false;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class Graphics
{
public:
	Graphics();
	Graphics(const Graphics&);
	~Graphics();

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Tick();

private:
	bool Render();

private:
	D3DLayer			*m_D3D;
	Camera				*m_Camera;
	Model				*m_Model;
	ModelObj			*m_ModelObj;
	ColorShader			*m_ColorShader;
	CellShadingShader	*m_CellShadingShader;
	TextureShader		*m_TextureShader;
	OutlineShader		*m_OutlineShader;
	int					m_RenderingMode;
	int					m_rotationAngle;

};

#endif