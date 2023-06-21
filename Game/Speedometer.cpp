#include "Speedometer.h"

Speedometer::Speedometer()
{
    Texture* backgroundTexture = new Texture();
    if (!backgroundTexture->loadFromFile("source/img/speedometr.png")) 
    {
        throw CustomException("File is not loaded!");
    }
    this->background = new Sprite(*backgroundTexture);
    background->setPosition(330, 340);
    Texture* arrowTexture = new Texture();
    if (!arrowTexture->loadFromFile("source/img/arrow.png")) //проверить размеры
    {
        throw CustomException("File is not loaded!");
    }
    this->arrow = new Sprite(*arrowTexture);
    arrow->setPosition(335, 440); //размеры
    this->speed = 0;
}

void Speedometer::draw(RenderTarget& target, RenderStates states) const
{
    background->setTextureRect(*visibleRectBackground);
    target.draw(*background, states);
    arrow->setTextureRect(*visibleRectArrow);
    target.draw(*arrow, states);
}
