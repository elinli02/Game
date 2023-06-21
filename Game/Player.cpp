#include "Player.h"

Player::Player()
{
    Texture* backgroundTexture = new Texture();
    if (!backgroundTexture->loadFromFile("source/img/backgroundPlayer(prob).png"))
    {
        throw CustomException("File not found");
    }
    background = new Sprite(*backgroundTexture);
    background->setPosition(Vector2f(0, 100));
    Texture* wheelTexture = new Texture();
    if (!wheelTexture->loadFromFile("source/img/wheelsPlayer.png"))
    {
        throw CustomException("File not found");
    }
    wheel = new Sprite(*wheelTexture);

}

void Player::draw(RenderTarget& target, RenderStates states) const
{
    background->setTextureRect(*visibleRectBackground);
    target.draw(*background, states);
    wheel->setTextureRect(*visibleRectWheel);
    wheel->setPosition(coordWheel[0]);
    target.draw(*wheel, states);
    wheel->setPosition(coordWheel[1]);
    target.draw(*wheel, states);
}
