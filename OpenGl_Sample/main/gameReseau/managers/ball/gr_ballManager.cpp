#include "gr_ballManager.hpp"
gr_ballManager* gr_ballManager::instance = nullptr;


gr_ballManager::~gr_ballManager()
{
	delete instance;
}

gr_ballManager* gr_ballManager::getInstance();
{
	if (instance == nullptr)
		instance = new gr_ballManager();

	return instance;
}
