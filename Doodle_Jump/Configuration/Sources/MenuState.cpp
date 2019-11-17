#include "..\Headers\MenuState.h"
#include <assert.h>
#include <iostream>

MenuState::MenuState(StateManager* stateManager)
    : m_stateManager(stateManager)
{
}

void MenuState::processInput(const sf::Event& e)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        setState(States::Game);
}

void MenuState::update(const float& delta) {}

void MenuState::render(sf::RenderWindow& app)
{
    app.draw(m_backgroundSprite);
    std::cout << "Menu" << std::endl;
}

void MenuState::init()
{
    assert(m_backgroundTexture.loadFromFile("Images/background.png"));
    m_backgroundSprite.setTexture(m_backgroundTexture);
}

void MenuState::setState(States newState) { m_stateManager->setState(newState); }
