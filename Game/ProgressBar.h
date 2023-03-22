#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "CustomException.h"
using namespace sf;
using namespace std;
class ProgressBar: public Drawable
{
    bool active=false;
    RectangleShape* background;
    RectangleShape* slider;
    Font* font;
    Text* text;
    int width;
    int height;
    int widthSlider;
    int heightSlider;
    int positionX = 300;
    int positionY = 120;
    int positionTextX = 110;
    int positionTextY = 120;
    int x = 100;
public:
    ProgressBar(string path, int width, int height, int widthSlider, int heightSlider, string label);
    
    void move(int x);
    void changeActive();
    //virtual void draw(RenderTarget& target, RenderStates states); //to do разобрать override
    void draw(RenderTarget& target, RenderStates states) const override;  //ќтсутствие const означает, что объ€влен новый метод вместо переопределени€ существующего виртуального метода
    //const €вл€етс€ частью функции
};

