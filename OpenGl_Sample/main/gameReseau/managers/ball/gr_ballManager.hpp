#pragma once

class gr_ballManager
{
private:
	static gr_ballManager* instance;


	~gr_ballManager();
public:
	static gr_ballManager* getInstance();



	
};