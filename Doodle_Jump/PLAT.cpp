#include "PLAT.h"
#include <iostream>

PLAT::PLAT(sf::Texture &texture)
{
	plat.setTexture(texture);
	x = rand() % 400;
	y = rand() % 533;
}


PLAT::~PLAT()
{
}

void PLAT::setTexture(sf::Texture & texture)
{
	plat.setTexture(texture);
}

void PLAT::setPosition( int& h, int& y, float& dy, int& x)
{
	y = h;
	this->y = this->y - dy;
	if (this->y > 533)
	{ 
		this->y = 0; 
		this->x = rand() % 400;
	}

	if ((x + 50 > this->x) && (x + 20 < this->x + 68) && (y + 70 > this->y) && (y + 70 < this->y + 10) && (dy > 0))  
		dy = -10;
	
	plat.setPosition(this->x, this->y);
}


void PLAT::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
	target.draw(this->plat, states);
}

void PLAT::points(int & result)
{
	if (this->y == 0)
	{
		result++;
	}
}

void PLAT::resetPlat(float& dx, float& dy, int& result)
{
	dx = 0;
	dy = 0;
	result = 0;
	this->y = rand() % 533;
	this->x = rand() % 400;
}

bool PLAT::lose()
{
	if (this->y < 0)
	{
		return true;
	}
	return false;

}



