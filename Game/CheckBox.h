#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "CustomException.h"
using namespace sf;
using namespace std;
class CheckBox: public sf::Drawable
{
    bool checked=false;
    RectangleShape* box;
    Font* font;
    Text* text;
    Text* symbol;
    int width = 20;
    int height = 20;
    int positionX;
    int positionY;
    int positionTextX = 160;
    int positionTextY = 185;
    string textChecked;
public:
    CheckBox(int positionX, int positionY, string label, string textChecked, bool checked = false);
    bool isChecked();
    void draw(RenderTarget& target, RenderStates states) const override;
    bool containsBound(int positionMouseX, int positionMouseY);
    void changeChecked();

};

