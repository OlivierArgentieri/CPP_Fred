#pragma once

// Include GLFW
#include <GLFW/glfw3.h>
#include <string>
#include <main/gameReseau/color/gr_color.hpp>

class gr_window
{
	float width;
	float height;
	std::string name;
	gr_color backgroundColor;
	
	GLFWwindow* window;
	
	void initGLFW();
	void initWindowSettings();
	void initMacSettings();
	void createWindow(const char* _titleWindow);

	
public:
	gr_window(float _width, float _height, const char* _title, const gr_color _color);
	void initWindow();
	void swapBuffer() const;
	
	int getKey(int _key) const;

	GLFWwindow* getWindow() const;
};
