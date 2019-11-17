#include "..\Headers\StateManager.h"
#include <assert.h>
#include "../Headers/GameState.h"
#include "../Headers/MenuState.h"
#include "../Headers/ResultsState.h"

StateManager::StateManager()
{
    if (m_instance == nullptr)
        m_instance = this;
    else
        assert(!"m_instance is not nullptr");
}

StateManager* StateManager::m_instance;
StateManager& StateManager::getInstance() { return *m_instance; }

void StateManager::changeState(States newState) 
{  
	switch (newState)
    {
        case StateManager::States::Menu:
			currentState = std::make_unique<State>
			break;
        case StateManager::States::Game:
            break;
        case StateManager::States::Results:
            break;
        default:
            break;
    }
}
