#include "../../GUI/Headers/TEXT.h"

TEXT::TEXT(float x, float y, std::string name, sf::RenderTarget& app)
{
	_x = x;
	_y = y;
	sf::Font font;
	font.loadFromFile("images/arial.ttf");
	Name.setFont(font);
	Name.setFillColor(sf::Color::Black);
	Name.setStyle(sf::Text::Bold);
	Name.setCharacterSize(32);
	Name.setString(name);
	sf::FloatRect text = Name.getLocalBounds();
	Name.setOrigin(text.left + text.width / 2.0f, text.top + text.height / 2.0f);
}

TEXT::~TEXT() {}

void TEXT::update(float deltaTime)
{
}

sf::Text TEXT::getTEXT()
{
	return Name;
}
