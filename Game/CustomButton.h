#pragma once
#include <SFML/Graphics.hpp>
#include<string.h>
#include<iostream>
using namespace sf;
using namespace std;
class CustomButton
{
private:
    RenderWindow* window;
    Sprite* sprite;
    Texture* texture;
    Texture* textureHover;

public:
    CustomButton(RenderWindow& window, string pathTexture, string pathHoverTexture, IntRect startPosition, float x, float y);
    void changeTextureButton(bool hover);
    FloatRect getGlobalBounds();
    void draw();
};

