#pragma once
#include<SFML/Graphics.hpp>
#include"CustomException.h"
using namespace std;
using namespace sf;
class Pedal: public Drawable
{
    Sprite* background;
    IntRect* visibleRectBackground = new IntRect(0, 0, 130, 130);
    Font* font;
    Text* text;
    int width;
    int height;
    int positionX = 300; //изменить
    int positionY = 200;
    int positionTextX = 110;
    int positionTextY = 120;
    float deltaSpeed = 0;
public:
    Pedal(string text, int positionX, int positionY, int positionTextX, int positionTextY, float deltaSpeed);
    void draw(RenderTarget& target, RenderStates states) const override;
    bool containBounds(int positionMouseX, int positionMouseY);
};

