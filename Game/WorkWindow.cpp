#include "WorkWindow.h"



WorkWindow::WorkWindow(int width, int height, string name, string pathBackground)
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    this->name = name;
    this->width = width;
    this->height = height;
    window = new RenderWindow(VideoMode(width, height), name);
    Texture *texture = new Texture();
    if (!texture->loadFromFile(pathBackground))
        throw CustomException("File is not loaded!");
    background = new Sprite(*texture);
    //todo выполнить обработку спрайта и создать метод для кнопок и запуска окна, метод для музыки
}

void WorkWindow::playMusic(string path)
{
    Music music;
    if (!music.openFromFile(path))
        throw EXIT_FAILURE;
    music.play();
    //"source/audio/music.ogg"
    //"source/audio/motor.ogg"
}

RenderWindow* WorkWindow::getWindow()
{
    return window;
}

void WorkWindow::setButtons(vector<CustomButton*> *buttons)
{
    this->buttons = buttons;
}

void WorkWindow::addButton(CustomButton* button)
{
    if (buttons == nullptr)
    {
        vector <CustomButton*> addButtons;
        buttons = &addButtons;
    }
    buttons->push_back(button);
}

void WorkWindow::start()
{
    if (name == "Start")
    {
        startMain();
    }
    
}
void WorkWindow::startMain()
{
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
            if (event.type == Event::MouseMoved)
            {
                for (int i = 0; i < buttons->size(); i++)
                {
                    if (buttons->at(i) != NULL)
                    {
                        if ((*(buttons->at(i))).getGlobalBounds().contains(mousePosF)) // arrayCustomButton[i]->getGlobalBounds()
                        {
                            buttons->at(i)->changeTextureButton(true);
                        }
                        else
                        {
                            buttons->at(i)->changeTextureButton(false);
                        }
                    }

                }

            }
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (buttons->at(0)->getGlobalBounds().contains(mousePosF))
                {
                    window->close();
                    //createWindow(textureGame);
                    //to do игровое окно
                }
                if (buttons->at(1)->getGlobalBounds().contains(mousePosF))
                {
                    window->close();
                    createSettings();
                    
                }
                if (buttons->at(2)->getGlobalBounds().contains(mousePosF))
                {
                    window->close();
                }
            }

        }

        window->clear();
        window->draw(*background); //отрисовка 

        for (int i = 0; i < buttons->size(); i++)
        {
            buttons->at(i)->draw();
        }
        window->display(); // вывод на экран контента
    }
}

void WorkWindow::createSettings()
{
    WorkWindow *settingsWindow = new WorkWindow(width, height, "Settings", "source/img/settings.jpg"); 
    RenderWindow* settings = settingsWindow->getWindow();
    IntRect startPosition1(0, 0, 92, 92);
    vector<CustomButton*> buttons; //*?
    CustomButton exitButton(*window, "source/img/exit1.png", "source/img/exit2.png", startPosition1, -(width - 92), -(height - 92));
    buttons.push_back(&exitButton);
    settingsWindow->setButtons(&buttons);
  // дописать все кнопки, которые находятся на этом окне settings
    //элементы sfml
}

WorkWindow::~WorkWindow()
{
    delete window;
    delete background;
    for (int i = 0; i < buttons->size(); i++)
    {
        delete buttons->at(i);
    }
    delete buttons;
    for (int i = 0; i < audios->size(); i++)
    {
        delete (* audios)[i];
    }
    delete audios;
}

