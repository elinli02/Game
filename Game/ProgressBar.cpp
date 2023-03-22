#include "ProgressBar.h"

ProgressBar::ProgressBar(string path, int width, int height, int widthSlider, int heightSlider, string label)
{
    //path
    this->width = width;
    this->height = height;
    this->widthSlider = widthSlider;
    this->heightSlider = heightSlider;
    background = new RectangleShape(Vector2f(width, height));
    background->setPosition(Vector2f(positionX, positionY));
    background->setFillColor(Color(173, 34, 233));
    slider = new RectangleShape(Vector2f(widthSlider, heightSlider));
    slider->setPosition(Vector2f(positionX + width, positionY - heightSlider / 5));
    slider->setFillColor(Color(0, 0, 0));
    font = new Font();
    //Font font; - вылетает критическая ошибка
    if (!font->loadFromFile("source/font/air-millhouse-italic3.ttf"))
    {
        throw CustomException("Font is not loaded!");
    }
    text = new Text(label, *font);
    text->setPosition(Vector2f(positionTextX, positionTextY));
    text->setFillColor(Color(0, 0, 0));
}

void ProgressBar::move(int x)
{
    //slider->left = 500 + width - width * (x / 100);
    //setPosition у slider 500 + width, 200 - heightSlider / 5,
}

void ProgressBar::changeActive()
{
    this->active = !this->active;
}

void ProgressBar::draw(RenderTarget& target, RenderStates states) const
{
    //states.transform *= getTransform();
    target.draw(*background, states);
    target.draw(*slider, states);
    target.draw(*text, states);
}

//void ProgressBar::draw(RenderTarget& target, RenderStates states)
//{
//    //states.transform *= getTransform();
//    target.draw(*background, states);
//}


