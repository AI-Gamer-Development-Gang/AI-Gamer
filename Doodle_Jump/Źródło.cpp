#include <SFML/Graphics.hpp>
#include "../Doodle_Jump/Configuration/Headers/StateManager.h"
#include <iostream>
#include <memory>
constexpr float delta = 1.0f / 60.0f;

int main()
{
    sf::RenderWindow app(sf::VideoMode(400, 533), "Doodle Game!");
    sf::Event e;
    const std::unique_ptr<StateManager> stateManager(std::make_unique<StateManager>());

    app.setFramerateLimit(60);
    float updateMultiplication{1.0f};
    float currentDelta{1.0f};
    bool exitStatus = EXIT_FAILURE;

    while (app.isOpen())
    {
        for (currentDelta = updateMultiplication * delta; currentDelta > 0.0f; currentDelta -= delta)
        {
            while (app.pollEvent(e))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    exitStatus = EXIT_SUCCESS;
                    app.close();
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket))
                    updateMultiplication *= 1.25f;
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket))
                    updateMultiplication *= 0.75f;
                else
                    stateManager->processInput(e);
            }

            if (currentDelta > delta)
                stateManager->update(delta);
            else
                stateManager->update(currentDelta);
        }

        stateManager->render(app);
    }
    return exitStatus | (stateManager->getEndStatus() ? EXIT_SUCCESS : EXIT_FAILURE);
}
