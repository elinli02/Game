#pragma once
#include<SFML/Graphics.hpp>
#include "CustomException.h"
using namespace sf;
class Speedometer: public Drawable
{
    Sprite* background;
    IntRect* visibleRectBackground = new IntRect(0, 0, 161, 161);
    Sprite* arrow;
    IntRect* visibleRectArrow = new IntRect(0, 0, 100, 100);
    float speed;
public:
    Speedometer();
    void draw(RenderTarget& target, RenderStates states) const override;
};

