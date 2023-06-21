#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class FuelProgressbar: public Drawable
{
    RectangleShape* background;
    RectangleShape* backgroundFuel;
    int width;
    int height;
    int widthFuel;
    int heightFuel;
    int positionX = 20; 
    int positionY = 30; 
    float x = 100;
public:
    FuelProgressbar(int width, int height);
    void draw(RenderTarget& target, RenderStates states) const override;
};

