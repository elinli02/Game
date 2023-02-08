#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include "CustomButton.h"
#include "WorkWindow.h"

using namespace sf;
void createWindow(Texture texture1);
int widthWindow = 800;
int heightWindow = 500;
int main()
{
    WorkWindow* windowStart = new WorkWindow(widthWindow, heightWindow, "Start", "source/img/picturebig.jpg");
    RenderWindow* window = windowStart->getWindow();
    /*HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    RenderWindow window(VideoMode(widhtWindow, heightWindow), "Game window");
    Texture texture;
    if (!texture.loadFromFile("source/img/picturebig.jpg"))
        return EXIT_FAILURE;
    Texture textureGame;
    if (!textureGame.loadFromFile("source/img/game.png"))
        return EXIT_FAILURE;
    Texture textureSetting;
    if (!textureSetting.loadFromFile("source/img/window2.jpg"))
        return EXIT_FAILURE;
    Sprite sprite(texture);*/

    /*Font font1;
    if (!font.loadFromFile("source/font/air-millhouse-italic3.ttf"))
        return EXIT_FAILURE;
    Text text1("Start", font, 120);
    text1.setPosition(460, 130);*/


    /*Music music;
    if (!music.openFromFile("source/audio/music.ogg"))
        return EXIT_FAILURE;
    music.play();

    Music music1;
    if (!music1.openFromFile("source/audio/motor.ogg"))
        return EXIT_FAILURE;
    music1.play();*/
    vector <CustomButton*> buttons;
    /*int countArrayCustomButton = 3;
    CustomButton** arrayCustomButton = new CustomButton*[countArrayCustomButton];*/
    //IntRect startPosition(0, 0, 187, 91);
    IntRect startPosition(0, 0, 143, 143);
    IntRect startPosition1(0, 0, 92, 92);
 
    CustomButton startButton(*window, "source/img/start1.png", "source/img/start2.png", startPosition, -330, -90);
    CustomButton settingButton(*window, "source/img/setting1.png", "source/img/setting2.png", startPosition1, -(widthWindow-92 - 92), -(heightWindow-92));
    CustomButton exitButton(*window, "source/img/exit1.png", "source/img/exit2.png", startPosition1, -(widthWindow - 92), -(heightWindow - 92));
    buttons.push_back(&startButton);
    buttons.push_back(&settingButton);
    buttons.push_back(&exitButton);
    /*arrayCustomButton[0] = &startButton;
    arrayCustomButton[1] = &settingButton;
    arrayCustomButton[2] = &exitButton;*/
    windowStart->setButtons(&buttons);

    /*if (!buttonStart.loadFromFile("source/img/start4.png"))
        return EXIT_FAILURE;
    if(!buttonStartHover.loadFromFile("source/img/start5.png"))
        return EXIT_FAILURE;*/

    /*if (!buttonSettings.loadFromFile("source/img/start1.png"))
        return EXIT_FAILURE;*/

    //Sprite startSprite(buttonStart);

    //Sprite settingsSprite(buttonSettings);

    /*startSprite.setTextureRect(startPosition);
    startSprite.setOrigin(-520, -150);*/
    windowStart->start();
    
}
void createWindow(Texture texture1)
{
    HWND hWnd1 = GetConsoleWindow();
    ShowWindow(hWnd1, SW_HIDE);
    RenderWindow window1(VideoMode(widthWindow, heightWindow), "Start window");
    
    Sprite sprite1(texture1);
    while (window1.isOpen())
    {
        Event event1;
        while (window1.pollEvent(event1))
        {
            if (event1.type == Event::Closed)
                window1.close();
        }
        window1.clear();
        window1.draw(sprite1);
        window1.display();
    }
}