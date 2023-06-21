#pragma once
#include<SFML/Graphics.hpp>
#include"CustomException.h"
using namespace std;
using namespace sf;
class Player: public Drawable
{
    Sprite* background;
    Sprite* wheel;
    vector<Vector2f> coordWheel = {{18, 215}, {98, 215}}; // 1 - заднее колесо, 2 - переднее колесо
    IntRect* visibleRectBackground = new IntRect(0, 5, 150, 200);
    IntRect* visibleRectWheel = new IntRect(0, 0, 33, 33);
    float angle = 0;
    float speed = 0;
    float fuel = 100;
public:
    Player();
    void draw(RenderTarget& target, RenderStates states) const override;

};

