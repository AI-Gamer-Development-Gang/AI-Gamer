#include "../Headers/GameState.h"

GameState::GameState(StateManager* stateManager)
    : m_isPlaying{true}
    , m_doodle{sf::Vector2f{10.0f, 10.0f}}
    , m_stateManager(stateManager)
	, m_TEXT_manager(1)
{
}

void GameState::processInput(const sf::Event& e)
{
    m_doodle.processInput(e);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        setState(States::Results);
}

void GameState::update(const float& delta)
{
    m_doodle.update(delta);
    m_platManager.update(delta);
}

void GameState::render(sf::RenderWindow& app)
{
    app.draw(m_backgroundSprite);
    m_doodle.render(app);
    m_platManager.render(app);
	m_TEXT_manager.render(app);
}

void GameState::init()
{
    assert(m_backgroundTexture.loadFromFile("Images/background.png"));
    m_backgroundSprite.setTexture(m_backgroundTexture);
}

void GameState::setState(States newState) { m_stateManager->setState(newState); }

//
// sf::Texture t1, t2, t3, t4;
// t3.loadFromFile("images/doodle.png");
// t4.loadFromFile("images/menu.jpg");
//
// sf::Text PointOut, LoseOut, PauseOut, Start, Start1, Nazwa, Exit, Exit1, Back, Back1, score,
// TryAgain, TryAgain1; sf::Sprite sBackground(t1), sPers(t3), sMenu(t4); sf::Font font;
// sf::Vector2i Mouse_Position;
//
// int x = 100, y = 100, h = 200;
// float dx = 0, dy = 0;
// bool pause{};
// int menu = 1;
// int result = 0;
// std::string str, yourscore = "Your score:";
//
// sMenu.setScale(1.31, 1.2);
// font.loadFromFile("images/arial.ttf");
// PointOut.setFont(font);
// PointOut.setFillColor(sf::Color::Black);
// PointOut.setStyle(sf::Text::Bold);
// PointOut.setCharacterSize(32);
// PointOut.setPosition(0, 30);
//
// score.setFont(font);
// score.setFillColor(sf::Color::Black);
// score.setStyle(sf::Text::Bold);
// score.setCharacterSize(32);
// score.setString(yourscore);
//
// PauseOut.setFont(font);
// PauseOut.setFillColor(sf::Color::Black);
// PauseOut.setStyle(sf::Text::Bold);
// PauseOut.setCharacterSize(64);
// PauseOut.setString("PAUSE");
// PauseOut.setOrigin(85, 32);
// PauseOut.setPosition(app.getSize().x / 2, app.getSize().y / 2);
//
// LoseOut.setFont(font);
// LoseOut.setFillColor(sf::Color::Red);
// LoseOut.setStyle(sf::Text::Bold);
// LoseOut.setCharacterSize(50);
// LoseOut.setString("YOU LOSE :(");
// LoseOut.setOrigin(110, 32);
// LoseOut.setPosition(app.getSize().x / 2, app.getSize().y / 2);
//
// Start.setFont(font);
// Start.setFillColor(sf::Color::Green);
// Start.setStyle(sf::Text::Bold);
// Start.setCharacterSize(32);
// Start.setString("START GAME");
// Start.setOrigin(85, 32);
// Start.setPosition(app.getSize().x / 2, 271);
//
// Start1.setFont(font);
// Start1.setFillColor(sf::Color::Red);
// Start1.setStyle(sf::Text::Bold);
// Start1.setCharacterSize(32);
// Start1.setString("START GAME");
// Start1.setOrigin(85, 32);
// Start1.setPosition(app.getSize().x / 2, 271);
//
// Nazwa.setFont(font);
// Nazwa.setFillColor(sf::Color::Green);
// Nazwa.setStyle(sf::Text::Bold);
// Nazwa.setCharacterSize(32);
// Nazwa.setString("Doodle Jump");
// Nazwa.setOrigin(85, 32);
// Nazwa.setPosition(app.getSize().x / 2, 53);
//
// Exit.setFont(font);
// Exit.setFillColor(sf::Color::Green);
// Exit.setStyle(sf::Text::Bold);
// Exit.setCharacterSize(32);
// Exit.setString("Exit");
// Exit.setOrigin(30, 32);
// Exit.setPosition(app.getSize().x / 2, 470);
//
// Exit1.setFont(font);
// Exit1.setFillColor(sf::Color::Red);
// Exit1.setStyle(sf::Text::Bold);
// Exit1.setCharacterSize(32);
// Exit1.setString("Exit");
// Exit1.setOrigin(30, 32);
// Exit1.setPosition(app.getSize().x / 2, 470);
//
// Back.setFont(font);
// Back.setFillColor(sf::Color::Green);
// Back.setStyle(sf::Text::Bold);
// Back.setCharacterSize(32);
// Back.setString("Back to menu");
// Back.setOrigin(85, 32);
// Back.setPosition(app.getSize().x / 2, 420);
//
// Back1.setFont(font);
// Back1.setFillColor(sf::Color::Red);
// Back1.setStyle(sf::Text::Bold);
// Back1.setCharacterSize(32);
// Back1.setString("Back to menu");
// Back1.setOrigin(85, 32);
// Back1.setPosition(app.getSize().x / 2, 420);
//
// TryAgain.setFont(font);
// TryAgain.setFillColor(sf::Color::Green);
// TryAgain.setStyle(sf::Text::Bold);
// TryAgain.setCharacterSize(32);
// TryAgain.setString("Try Again");
// TryAgain.setOrigin(65, 32);
// TryAgain.setPosition(app.getSize().x / 2, 370);
//
// TryAgain1.setFont(font);
// TryAgain1.setFillColor(sf::Color::Red);
// TryAgain1.setStyle(sf::Text::Bold);
// TryAgain1.setCharacterSize(32);
// TryAgain1.setString("Try Again");
// TryAgain1.setOrigin(65, 32);
// TryAgain1.setPosition(app.getSize().x / 2, 370);
//
// Plat plat1(t2);
// Plat plat2(t2);
// Plat plat3(t2);
// Plat plat4(t2);
// Plat plat5(t2);
// Plat plat6(t2);
// Plat plat7(t2);
// Plat plat8(t2);
// Plat plat9(t2);
// Plat plat10(t2);
//
// while (app.isOpen())
//{
//	sf::Event e;
//	while (app.pollEvent(e))
//	{
//		if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//			app.close();
//
//		if (e.type == sf::Event::MouseMoved)
//		{
//			Mouse_Position = sf::Mouse::getPosition(app);
//		}
//	}
//
//	if (menu == 1)
//	{
//		app.draw(sMenu);
//		app.draw(Start);
//		app.draw(Nazwa);
//		app.draw(Exit);
//
//		if (Mouse_Position.x >= 170 && Mouse_Position.x <= 220 && Mouse_Position.y >= 445 &&
// Mouse_Position.y <= 470)
//		{
//			app.draw(Exit1);
//			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//			{
//				app.close();
//			}
//		}
//
//		if (Mouse_Position.x >= 113 && Mouse_Position.x <= 298 && Mouse_Position.y >= 243 &&
// Mouse_Position.y <= 273)
//		{
//			app.draw(Start1);
//			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//			{
//				plat1.resetPlat(dx, dy, result);
//				plat2.resetPlat(dx, dy, result);
//				plat3.resetPlat(dx, dy, result);
//				plat4.resetPlat(dx, dy, result);
//				plat5.resetPlat(dx, dy, result);
//				plat6.resetPlat(dx, dy, result);
//				plat7.resetPlat(dx, dy, result);
//				plat8.resetPlat(dx, dy, result);
//				plat9.resetPlat(dx, dy, result);
//				plat10.resetPlat(dx, dy, result);
//
//				menu = 2;
//			}
//		}
//	}
//
//	if (menu == 2)
//	{
//		app.draw(sBackground);
//		app.draw(sPers);
//		app.draw(plat1);
//		app.draw(plat2);
//		app.draw(plat3);
//		app.draw(plat4);
//		app.draw(plat5);
//		app.draw(plat6);
//		app.draw(plat7);
//		app.draw(plat8);
//		app.draw(plat9);
//		app.draw(plat10);
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//		{
//			if (!pause)
//			{
//				pause = true;
//				sf::sleep(sf::seconds(0.2));
//			}
//			else
//			{
//				pause = false;
//				sf::sleep(sf::seconds(0.2));
//			}
//		}
//
//
//		if (!pause)
//		{
//
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) x += 3;
//			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) x -= 3;
//
//			dy += 0.2;
//			y += dy;
//			if (y > 500)
//				dy = -10;
//
//
//			plat1.setPosition(h, y, dy, x);
//			plat2.setPosition(h, y, dy, x);
//			plat3.setPosition(h, y, dy, x);
//			plat4.setPosition(h, y, dy, x);
//			plat5.setPosition(h, y, dy, x);
//			plat6.setPosition(h, y, dy, x);
//			plat7.setPosition(h, y, dy, x);
//			plat8.setPosition(h, y, dy, x);
//			plat9.setPosition(h, y, dy, x);
//			plat10.setPosition(h, y, dy, x);
//
//			if (result == 0)
//			{
//				int n = 533;
//				if (n > 500)
//					dy = -10;
//			}
//
//			if (x >= 400)
//				x = -65;
//			else if (x <= -65)
//				x = 399;
//			sPers.setPosition(x, y);
//
//			std::ostringstream itos_points;
//			itos_points << result;
//			str = itos_points.str();
//			app.draw(score);
//			plat1.points(result);
//			PointOut.setString(str);
//			app.draw(PointOut);
//
//			if (plat1.lose() && plat2.lose() && plat3.lose() && plat4.lose() &&
// plat5.lose()
//&& plat6.lose() && plat7.lose() && plat8.lose() && plat9.lose() && plat10.lose())
//			{
//				app.draw(LoseOut);
//				app.draw(Exit);
//				app.draw(Back);
//				app.draw(TryAgain);
//
//				if (Mouse_Position.x >= 170 && Mouse_Position.x <= 220 &&
// Mouse_Position.y
//>= 445 && Mouse_Position.y <= 470)
//				{
//					app.draw(Exit1);
//					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//					{
//						app.close();
//					}
//				}
//
//				if (Mouse_Position.x >= 115 && Mouse_Position.x <= 285 &&
// Mouse_Position.y
//>= 395 && Mouse_Position.y <= 420)
//				{
//					app.draw(Back1);
//					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//					{
//						menu = 1;
//					}
//				}
//
//				if (Mouse_Position.x >= 130 && Mouse_Position.x <= 270 &&
// Mouse_Position.y
//>= 345 && Mouse_Position.y <= 370)
//				{
//					app.draw(TryAgain1);
//					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//					{
//						plat1.resetPlat(dx, dy, result);
//						plat2.resetPlat(dx, dy, result);
//						plat3.resetPlat(dx, dy, result);
//						plat4.resetPlat(dx, dy, result);
//						plat5.resetPlat(dx, dy, result);
//						plat6.resetPlat(dx, dy, result);
//						plat7.resetPlat(dx, dy, result);
//						plat8.resetPlat(dx, dy, result);
//						plat9.resetPlat(dx, dy, result);
//						plat10.resetPlat(dx, dy, result);
//						menu = 2;
//					}
//				}
//
//				do
//				{
//					sPers.move(-1, 0);
//				} while (sPers.getPosition().x >= 5);
//			}
//		}
//		else
//			app.draw(PauseOut);
//	}
//	app.display();
//}
