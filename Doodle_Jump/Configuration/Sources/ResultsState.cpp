#include "..\Headers\ResultsState.h"
#include <assert.h>
#include <iostream>

ResultsState::ResultsState(StateManager* stateManager)
    : m_stateManager(stateManager)
{
}

void ResultsState::processInput(const sf::Event& e)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        setState(States::Menu);
}

void ResultsState::update(const float& delta) {}

void ResultsState::render(sf::RenderWindow& app)
{
    app.draw(m_backgroundSprite);
    std::cout << "Results" << std::endl;
}

void ResultsState::init()
{
    assert(m_backgroundTexture.loadFromFile("Images/background.png"));
    m_backgroundSprite.setTexture(m_backgroundTexture);
}

void ResultsState::setState(States newState) { m_stateManager->setState(newState); }
//trzymajmy sie konwencji - jesli wszystkie definicje sa rozwalone na pare linijek to nawet te krotkie niech tez beda
