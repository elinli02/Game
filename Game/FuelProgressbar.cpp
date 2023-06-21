#include "FuelProgressbar.h"

FuelProgressbar::FuelProgressbar(int width, int height)
{
    this->width = width;
    this->height = height;
    background = new RectangleShape(Vector2f(width, height));
    background->setFillColor(Color(0, 0, 0, 120));
    background->setPosition(Vector2f(positionX, positionY));
    backgroundFuel = new RectangleShape(Vector2f(width, height));
    backgroundFuel->setFillColor(Color(213, 217, 132));
    backgroundFuel->setPosition(Vector2f(positionX, positionY));
}

void FuelProgressbar::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(*background, states);
    target.draw(*backgroundFuel, states);
}
