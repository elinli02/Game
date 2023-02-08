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
    RenderWindow* window;
    Sprite* background;
    vector<CustomButton*> *buttons;
    vector<Music*> *audios;
    string name;
    int height;
    int width;
    void startMain();
    void createSettings();
public:
    WorkWindow(int width, int height, string name, string pathBackground);
    void playMusic(string path);
    RenderWindow* getWindow();
    void setButtons(vector<CustomButton*> *buttons);
    void addButton(CustomButton* button);
    void start();
    ~WorkWindow();
};

