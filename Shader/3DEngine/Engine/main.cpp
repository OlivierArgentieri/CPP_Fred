////////////////////////////////////////////////////////////////////////////////
// Filename: main.cpp
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "System.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	bool result;
	
	
	// Create the system object.
	System *pSystem = new System();
	if(!pSystem)
	{
		return 0;
	}

	// Initialize and run the system object.
	result = pSystem->Initialize( hInstance );
	if(result)
	{
		pSystem->Run();
	}

	// Shutdown and release the system object.
	pSystem->Shutdown();
	delete pSystem;
	pSystem = 0;

	return 0;
}