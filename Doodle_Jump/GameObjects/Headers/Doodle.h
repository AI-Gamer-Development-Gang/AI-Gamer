#include <SFML/Graphics.hpp>
#include <assert.h>

class Doodle
{
  public:
    enum class MoveDirection
    {
		NONE = 0,
        RIGHT = 1,
        LEFT  = 2
    };
    Doodle(const sf::Vector2f& defaultPosition);
    ~Doodle();
    void update(float deltaTime);
    void render(sf::RenderTarget& app);
    void setDefaultPosition(const sf::Vector2f& newDefaultPosition);
    void setPosition(const sf::Vector2f& newPosition);
    void move(const MoveDirection moveDirection);
    void resetPosition();
    void processInput(const sf::Event& e);

  private:
    sf::Vector2f m_defaultPosition;
    sf::Vector2f m_position;
    sf::Sprite m_doodleSprite;//TODO
    sf::Texture m_doodleTexture;//TODO
    bool m_dirty;
    MoveDirection m_movingDirection;
};
