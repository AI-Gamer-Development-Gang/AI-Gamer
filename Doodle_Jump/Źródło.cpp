#include "../Doodle_Jump/Game/Game.h"
#include <iostream>
#include <memory>
constexpr float delta = 1.0f / 60.0f;

int main()
{
    sf::RenderWindow app(sf::VideoMode(400, 533), "Doodle Game!");
    sf::Event e;
    const std::unique_ptr<Game> game(std::make_unique<Game>());

    app.setFramerateLimit(60);
    float updateMultiplication{1.0f};
    bool exitStatus = EXIT_FAILURE;

    while (app.isOpen())
    {
        for (auto i = delta * updateMultiplication; i > 0.0f; i -= delta)
        {
            while (app.pollEvent(e))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                {
                    exitStatus = EXIT_SUCCESS;
                    app.close();
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket))
                    updateMultiplication *= 1.5f;
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket))
                    updateMultiplication *= 0.5f;
                else
                    game->processInput(e);
            }
            game->update(delta * updateMultiplication);
        }
        game->render(app);
    }
    return exitStatus | (game->getEndStatus() ? EXIT_SUCCESS : EXIT_FAILURE);
}
