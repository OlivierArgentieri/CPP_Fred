#include "gr_player.hpp"
#include "main/gameReseau/managers/input/gr_inputManager.hpp"

void gr_player::OnMove(glm::vec2 _axisValues)
{
	if (!ball) return;

	if(_axisValues != glm::vec2())
		ball->SetPosition(ball->GetTransform().position + glm::vec3(_axisValues.x*0.1, 0, _axisValues.y*0.1));
}

void gr_player::RegisterToInputManager(gr_inputManager* _inputManager)
{
	__hook(&gr_inputManager::OnMove, _inputManager, &gr_player::OnMove);
}

void gr_player::UnRegisterToInputManager(gr_inputManager* _inputManager)
{
	__unhook(&gr_inputManager::OnMove, _inputManager, &gr_player::OnMove);
}

gr_player::gr_player(gr_ball* _ball)
{
	ball = _ball;
	RegisterToInputManager(gr_inputManager::getInstance());
}