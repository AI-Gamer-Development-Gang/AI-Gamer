#include "../Headers/StateManager.h"
#include "../Headers/GameState.h"
#include "../Headers/MenuState.h"
#include "../Headers/ResultsState.h"
#include <assert.h>

StateManager::StateManager()
    : m_exitStatus{0}
{
    if (m_instance == nullptr)
        m_instance = this;
    else
        assert(!"m_instance is not nullptr");

    setState(State::States::Menu);
}

StateManager* StateManager::m_instance;
StateManager& StateManager::getInstance() { return *m_instance; }

void StateManager::setState(State::States newState)
{
    switch (newState)
    {
    case State::States::Menu:
        m_currentState = std::make_unique<MenuState>(m_instance);
        break;
    case State::States::Game:
        m_currentState = std::make_unique<GameState>(m_instance);
        break;
    case State::States::Results:
        m_currentState = std::make_unique<ResultsState>(m_instance);
        break;
    default:
        break;
    }

    m_currentState->init();
}

void StateManager::processInput(const sf::Event& e) { m_currentState->processInput(e); }

void StateManager::update(const float& delta) { m_currentState->update(delta); }

void StateManager::render(sf::RenderWindow& app)
{
    app.setActive();
    app.clear();
    m_currentState->render(app);
    app.display();
}

const bool StateManager::getEndStatus() const { return m_exitStatus; }
