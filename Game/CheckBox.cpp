#include "CheckBox.h"

CheckBox::CheckBox(int positionX, int positionY, string label, bool checked)
{
    this->checked = checked;
    box = new RectangleShape(Vector2f(width, height));
    box->setPosition(Vector2f(positionX, positionY));
    box->setFillColor(Color(255, 255, 255));
    font = new Font();
    if (!font->loadFromFile("source/font/air-millhouse-italic3.ttf"))
    {
        throw CustomException("Font is not loaded!");
    }
    text = new Text(label, *font);
    text->setPosition(Vector2f(positionTextX, positionTextY));
    text->setFillColor(Color(0, 0, 0));
}

bool CheckBox::isChecked()
{
    return checked;
}

void CheckBox::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(*box, states);
    target.draw(*text, states);
}
