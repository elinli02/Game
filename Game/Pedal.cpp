#include "Pedal.h"
Pedal::Pedal(string text, int positionX, int positionY, int positionTextX, int positionTextY, float deltaSpeed)
{
    Texture* backgroundTexture = new Texture();
    if (deltaSpeed < 0)
    {
        if (!backgroundTexture->loadFromFile("source/img/brake.png"))
        {
            throw CustomException("Img is not loaded!");
        }
    }
    else
    {
        if (!backgroundTexture->loadFromFile("source/img/gas.png"))
        {
            throw CustomException("Img is not loaded!");
        }
    }

    background = new Sprite(*backgroundTexture, IntRect(positionX, positionY, width, height));
    background->setPosition(Vector2f(positionX, positionY));



    this->width = 80;
    this->height = 80;
    this->positionX = positionX;
    this->positionY = positionY;
    this->positionTextX = positionTextX;
    this->positionTextY = positionTextY;
    this->deltaSpeed = deltaSpeed;
    font = new Font();
    if (!font->loadFromFile("source/font/air-millhouse-italic3.ttf"))
    {
        throw CustomException("Font is not loaded!");
    }
    this->text = new Text(text, *font);
    this->text->setPosition(Vector2f(positionTextX, positionTextY));
    this->text->setFillColor(Color(255, 255, 255));
}

void Pedal::draw(RenderTarget& target, RenderStates states) const
{
    background->setTextureRect(*visibleRectBackground);
    target.draw(*background, states);
    target.draw(*text, states);
}

bool Pedal::containBounds(int positionMouseX, int positionMouseY)
{
    return (positionMouseX > positionX && positionMouseX<positionX + width && positionMouseY>positionY && positionMouseY < positionY + height);
}
