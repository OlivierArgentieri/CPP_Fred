#pragma once

// Include GLFW
#include <GLFW/glfw3.h>
#include <string>


class gr_window
{
	float width;
	float height;
	std::string name;
	
	GLFWwindow* window;
	
	void InitGLFW();
	void InitWindowSettings();
	void InitMacSettings();
	void CreateWindow(const char* _titleWindow);
	
public:
	gr_window(float _width, float _height, const char* _title);
	void InitWindow();
	void SwapBuffer() const;
	
	int GetKey(int _key) const;

	GLFWwindow* GetWindow() const;
};