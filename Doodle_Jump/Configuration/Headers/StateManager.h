#pragma once

#include "State.h"
#include <memory>

class State;
class StateManager
{
  private:
    std::unique_ptr<State> m_currentState;
    static StateManager* m_instance;
    bool m_exitStatus;

  public:
    StateManager();
    StateManager(const StateManager&) = delete;
    StateManager& operator=(const StateManager&) = delete;
    ~StateManager()                              = default;

    StateManager& getInstance();
    void setState(State::States newState);

    void processInput(const sf::Event& e);
    void update(const float& delta);
    void render(sf::RenderWindow& app);

    const bool getEndStatus() const;
};
