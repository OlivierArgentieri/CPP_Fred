#pragma once

class gr_time
{
private:

	static double currentTime;
	static double oldTime;
	static float deltaTime;
	
public:
	gr_time();

	static float getDeltaTime();
	static void beginFrame();
	static void endFrame();
};