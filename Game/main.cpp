#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include "CustomButton.h"

using namespace sf;
void createWindow(Texture texture1);
int widhtWindow = 800;
int heightWindow = 500;
int main()
{
    HWND hWnd = GetConsoleWindow();
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
    Sprite sprite(texture);

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

    int countArrayCustomButton = 3;
    CustomButton** arrayCustomButton = new CustomButton*[countArrayCustomButton];
    //IntRect startPosition(0, 0, 187, 91);
    IntRect startPosition(0, 0, 143, 143);
    IntRect startPosition1(0, 0, 92, 92);
    //CustomButton startButton(window, "source/img/start4.png", "source/img/start5.png", startPosition, -520, -150);
    CustomButton startButton(window, "source/img/start1.png", "source/img/start2.png", startPosition, -530, -150);
    CustomButton settingButton(window, "source/img/setting1.png", "source/img/setting2.png", startPosition1, -(widhtWindow-92 - 92), -(heightWindow-92));
    CustomButton exitButton(window, "source/img/exit1.png", "source/img/exit2.png", startPosition1, -(widhtWindow - 92), -(heightWindow - 92));
    arrayCustomButton[0] = &startButton;
    arrayCustomButton[1] = &settingButton;
    arrayCustomButton[2] = &exitButton;
    //Texture buttonStart;
    //Texture buttonStartHover;

    //Texture buttonSettings;

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


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            Vector2i mousePos = Mouse::getPosition(window);
            Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::MouseMoved)
            {
                for (int i = 0; i < countArrayCustomButton; i++)
                {
                    if (arrayCustomButton[i] != NULL)
                    {
                        if ((*(arrayCustomButton[i])).getGlobalBounds().contains(mousePosF)) // arrayCustomButton[i]->getGlobalBounds()
                        {
                            arrayCustomButton[i]->changeTextureButton(true);
                        }
                        else
                        {
                            arrayCustomButton[i]->changeTextureButton(false);
                        }
                    }
                    
                }
                
            }
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (startButton.getGlobalBounds().contains(mousePosF))
                {
                    window.close();
                    createWindow(textureGame);
                }
                if (settingButton.getGlobalBounds().contains(mousePosF))
                {
                    window.close();
                    createWindow(textureSetting);
                }
                if (exitButton.getGlobalBounds().contains(mousePosF))
                {
                    window.close();
                }
            }
            
        }
        
        window.clear();
        window.draw(sprite); //отрисовка 
        //window.draw(text);
        //window.draw(text1);
        startButton.draw();
        settingButton.draw();
        exitButton.draw();
        //window.draw(startSprite);
        window.display(); // вывод на экран контента
    }
    
}
void createWindow(Texture texture1)
{
    HWND hWnd1 = GetConsoleWindow();
    ShowWindow(hWnd1, SW_HIDE);
    RenderWindow window1(VideoMode(widhtWindow, heightWindow), "Start window");
    
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