#include "../../GUI/Headers/TEXT_manager.h"
#include <iostream>

TEXT_manager::TEXT_manager(sf::RenderTarget& app)
{
	TEXT Start(200, 250, "Start game", app);
	_text.push_back(Start);
}

TEXT_manager::TEXT_manager()
{
}

void TEXT_manager::update(float deltaTime)
{
}

void TEXT_manager::render(sf::RenderTarget& app)
{
	//app.draw(_text[0].getTEXT());
}
