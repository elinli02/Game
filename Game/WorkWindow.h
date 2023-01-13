#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<vector>
#include"CustomButton.h"
#include"CustomException.h"
#include <Windows.h>
using namespace sf;
using namespace std;
class WorkWindow
{
    // todo прописывать текстуру для окна, функционал каждого окна за исключением игрового
    // 3 функции для каждого окна
    Sprite* background;
    vector<CustomButton*> buttons;
    vector<Music*> audios;
public:
    WorkWindow(int width, int height, string name, string pathBackground);
};

