#pragma once
#include<SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<vector>
#include"CustomException.h"
#include <Windows.h>
#include "Pedal.h"
#include "Coin.h"
#include "Fuel.h"
#include "FuelProgressbar.h"
#include "Player.h"
#include "Speedometer.h"
#include"CustomButton.h"
using namespace sf;
class Game
{
    RenderWindow* window;
    Sprite* background;
    Font* font;
    Text* textDistance;
    Text* textCoin;
    const int widthWindow = 800; 
    const int heightWindow = 500;
    string name = "Game";
    string pathBackground = "source/img/gameWindow.png";
    int positionTextDistanceX = 110;
    int positionTextDistanceY = 120;
    int positionTextCoinX = 120;
    int positionTextCoinY = 120;
    int distance = 0;
    int coin = 0;
    Game(float volume, bool checkDistance);
    static Game* instance;
    static Music* music;
    static string pathMusic;
    Pedal* gas;
    Pedal* brake;
    Player* player;
    vector <Coin*> coins;
    vector <Fuel*> fuels;
    Speedometer* speedometer;
    FuelProgressbar* fuelProgressbar;
    void startLoop();
public:
    static void start(float volume, bool checkDistance);
};

