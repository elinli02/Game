#include "Game.h"
Game* Game::instance = nullptr;
Music* Game::music = new Music();
string Game::pathMusic = "source/audio/gameMusic.ogg"; 
Game::Game(float volume, bool checkDistance)
{
    //to do установить звук
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    window = new RenderWindow(VideoMode(widthWindow, heightWindow), name);
    Texture* texture = new Texture();
    if (!texture->loadFromFile(pathBackground))
        throw CustomException("File is not loaded!");
    background = new Sprite(*texture);
    background->setPosition(0, 0); 
    gas = new Pedal("gas", 650, 370, 692, 330, 1); 
    brake = new Pedal("brake", 20, 370, 55, 330, -1);
    player = new Player();
    speedometer = new Speedometer(); 
    fuelProgressbar = new FuelProgressbar(50, 20);
}

void Game::startLoop()
{
    bool flagAction = false;
    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            Vector2i mousePos = Mouse::getPosition(*window);
            Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            if (event.type == Event::Closed)
            {
                window->close();
            }
            
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                flagAction = true;
                if (gas->containBounds(mousePos.x, mousePos.y))
                {
                    //слздать getter получения deltaspeed, чтобы получить скорость и изменить(settter?)
                  
                }
                if (brake->containBounds(mousePos.x, mousePos.y))
                {
                    
                }
                
            }
            else
            {
                flagAction = false;
            }

        }

        window->clear();
        window->draw(*background); //отрисовка 
        //to do нарисовать землю
        window->draw(*speedometer); //не отрисовывается стрелка
        window->draw(*gas);
        window->draw(*brake);
        window->draw(*fuelProgressbar);

        window->draw(*player);

        window->display(); // вывод на экран контента

    }
}
void Game::start(float volume, bool checkDistance)
{
    if (instance == nullptr)
    {
        if (!music->openFromFile(pathMusic))
            throw EXIT_FAILURE;
        //music->play();
        instance = new Game(volume, checkDistance);
        instance->startLoop();
    }
}
