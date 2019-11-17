#pragma once

#include "State.h"
#include <memory>

class StateManager
{
  private:
    std::unique_ptr<State> currentState;
    static StateManager* m_instance;

  public:
    StateManager();
    StateManager(const StateManager&) = delete;
    StateManager& operator=(const StateManager&) = delete;
    ~StateManager()                              = default;

    enum class States
    {
        Menu    = 0,
        Game    = 1,
        Results = 2
    };
    StateManager& getInstance();
    void changeState(States newState);
};
