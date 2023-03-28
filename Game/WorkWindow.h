#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<vector>
#include"CustomButton.h"
#include"CustomException.h"
#include <Windows.h>
#include "ProgressBar.h"
#include "CheckBox.h"
using namespace sf;
using namespace std;
class WorkWindow
{
    RenderWindow* window;
    Sprite* background;
    ProgressBar* progressbar;
    CheckBox* checkbox;
    //vector<Drawable*> elements;
    vector<CustomButton*> *buttons;
    vector<Music*> *audios = new vector<Music*>;
    string name;
    int width;
    int height;
    static void createMain();
    void startMain();
    void createSettings();
    void startSettings();
    WorkWindow(int width, int height, string name, string pathBackground);
    void playMusic(string path);
    RenderWindow* getWindow();
    void setButtons(vector<CustomButton*>* buttons);
    void addButton(CustomButton* button);
    void start();
    ~WorkWindow();
    static const int widthWindow = 800;
    static const int heightWindow = 500;
    static Music* mainMusic;
    static void startMainMusic(string path);
    void saveSettings();
    //SoundBuffer soundBuffer;
    //Sound sound;
public:
    static void startApplication();
    
};

