#include "gr_time.hpp"

#include "GLFW/glfw3.h"

double gr_time::currentTime = 0;;
double gr_time::oldTime = 0;;
float gr_time::deltaTime = 0;;

gr_time::gr_time()
{ /* not used */ }

float gr_time::getDeltaTime()
{
	return deltaTime;
}

void gr_time::beginFrame()
{
	oldTime = glfwGetTime();
}


void gr_time::endFrame()
{
	currentTime = glfwGetTime();

	deltaTime = float(currentTime - oldTime);
	oldTime = currentTime;
}