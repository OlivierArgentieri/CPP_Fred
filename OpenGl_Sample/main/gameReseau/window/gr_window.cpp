#include "gr_window.hpp"
#include <main/gameReseau/color/gr_color.hpp>

void gr_window::initGLFW()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
	}
}


void gr_window::initWindowSettings()
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void gr_window::initMacSettings()
{
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
}


void gr_window::createWindow(const char* _titleWindow)
{
	initGLFW();
	window = glfwCreateWindow(width, height, _titleWindow, NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
	}
}

gr_window::gr_window(float _width, float _height, const char* _title, const gr_color _color)
{
	width = _width;
	height = _height;
	createWindow(_title);
	backgroundColor = gr_color(_color);
}

void gr_window::initWindow()
{
	initWindowSettings();

	initMacSettings();
	glfwMakeContextCurrent(window);


	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	// Hide the mouse and enable unlimited mouvement
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set the mouse at the center of the screen
	glfwPollEvents();
	glfwSetCursorPos(window, width / 2, height / 2);

	// Dark blue background
	glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

}

void gr_window::swapBuffer() const
{
	glfwSwapBuffers(window);
}

int gr_window::getKey(int _key) const
{
	return glfwGetKey(window, _key);
}

GLFWwindow* gr_window::getWindow() const
{
	return window;
}