#include "../../GUI/Headers/TEXT_manager.h"
#include <iostream>


TEXT_manager::TEXT_manager(int m_state)
{
	switch (m_state)
	{
	case 0:
		m_texts.emplace_back(std::make_unique<TEXT>(200.f, 53.f, "DOODLE JUMP"));
		m_texts.emplace_back(std::make_unique<TEXT>(200.f, 271.f, "START GAME"));
		m_texts.emplace_back(std::make_unique<TEXT>(200.f, 470.f, "EXIT"));
		break;
	case 1:
		m_texts.emplace_back(std::make_unique<TEXT>(100.f, 21.f, "YOUR SCORE:"));
		break;
	case 2:
		m_texts.emplace_back(std::make_unique<TEXT>(200.f, 420.f, "BACK TO MENU"));
		m_texts.emplace_back(std::make_unique<TEXT>(200.f, 370.f, "TRY AGAIN"));
		m_texts.emplace_back(std::make_unique<TEXT>(200.f, 470.f, "EXIT"));
		break;
	default:
		break;
	}
}

TEXT_manager::~TEXT_manager() { }

void TEXT_manager::update(float deltaTime) { }

void TEXT_manager::render(sf::RenderTarget& app)
{
	for (auto& text : m_texts)
	{
		text->render(app);
	}
}
