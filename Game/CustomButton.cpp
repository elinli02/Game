#include "CustomButton.h"

CustomButton::CustomButton(RenderWindow& window, string pathTexture, string pathHoverTexture, IntRect startPosition, float x, float y)
{
    this->window = &window;
    this->texture = new Texture();
    if (!texture->loadFromFile(pathTexture))
        throw invalid_argument("file texture");
    this->textureHover = new Texture();
    if (!textureHover->loadFromFile(pathHoverTexture))
        throw invalid_argument("file hover texture");
    this->sprite = new Sprite(*texture);
    this->sprite->setTextureRect(startPosition);
    this->sprite->setOrigin(x, y);
}

void CustomButton::changeTextureButton(bool hover)
{
    if (hover)
    {
        sprite->setTexture(*textureHover);
    }
    else
    {
        sprite->setTexture(*texture);
    }
}

FloatRect CustomButton::getGlobalBounds()
{
    return sprite->getGlobalBounds();
}

void CustomButton::draw()
{
    window->draw(*sprite);
}
