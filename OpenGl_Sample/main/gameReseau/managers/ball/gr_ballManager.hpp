#pragma once
#include <glm/detail/type_vec3.hpp>
#include <vector>

class gr_ball;

class gr_ballManager
{
private:
	static gr_ballManager* instance;
	
	std::vector<gr_ball*> balls;
	bool TestCollision(gr_ball * _ball);
	~gr_ballManager();
	
public:
	
	static gr_ballManager* getInstance();
	void addBalls(gr_ball* _ball);
	void makeSpawn(unsigned _nbItem, float _minPositionX, float _maxPositionX, float _minPositionY, float _maxPositionY, float _minPositionZ, float _maxPositionZ);
	void Clear();
	void DeleteAll();
	void Update();
	std::vector<gr_ball*> GetAllBall() const;
};
