#include <SFML/Graphics.hpp>
#include <sstream>

class PLAT : public  sf::Drawable
{
private:
	int x, y;
	sf::Sprite plat;
public:

	PLAT(sf::Texture &texture);
	~PLAT();
	void setTexture(sf::Texture &texture);
	void setPosition(int& h, int& y, float& dy, int& x);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void points(int& result);
	bool lose();
	void resetPlat(float& dx, float& dy, int& result);
};

