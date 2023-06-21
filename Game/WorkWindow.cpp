#include "WorkWindow.h"

Music* WorkWindow::mainMusic = new Music();

void WorkWindow::startMainMusic(string path)
{
    if (!mainMusic->openFromFile(path))
        throw EXIT_FAILURE;
    mainMusic->play();
}

void WorkWindow::saveSettings()
{
    //to do сохранить в файл checkbox и progressbar
}

void WorkWindow::startApplication()
{
    startMainMusic("source/audio/music.ogg");
    createMain();
    
}


WorkWindow::WorkWindow(int width, int height, string name, string pathBackground, User* user)

{
    this->user = user;
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
}

void WorkWindow::playMusic(string path)
{

    /*if (!soundBuffer.loadFromFile(path))
        throw EXIT_FAILURE;
    sound.setBuffer(soundBuffer);
    sound.play();*/
    Music* newMusic = new Music();
    audios->push_back(newMusic);
    if (!newMusic->openFromFile(path))
        throw EXIT_FAILURE;
    newMusic->play();

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
    else if (name == "Settings")
    {
        startSettings();
    }
    
}
void WorkWindow::createMain()
{
    WorkWindow* windowStart = new WorkWindow(widthWindow, heightWindow, "Start", "source/img/picturebig.jpg");
    RenderWindow* window = windowStart->getWindow();
   
    //windowStart->playMusic("source/audio/motor.ogg");
    

    vector <CustomButton*> buttons;
    /*int countArrayCustomButton = 3;
    CustomButton** arrayCustomButton = new CustomButton*[countArrayCustomButton];*/
    //IntRect startPosition(0, 0, 187, 91);
    IntRect startPosition(0, 0, 143, 143);
    IntRect startPosition1(0, 0, 92, 92);

    CustomButton startButton(*window, "source/img/start1.png", "source/img/start2.png", startPosition, -330, -90);
    CustomButton settingButton(*window, "source/img/setting1.png", "source/img/setting2.png", startPosition1, -(widthWindow - 92 - 92), -(heightWindow - 92));
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
                    Database* db = Database::getInstance();
                    user = db->selectInf(1);
                    window->close();
                    for (int i = 0; i < audios->size(); i++)
                    {
                        audios->at(i)->stop();
                    } 
                    mainMusic->pause();                                               // добавлено
                    Game::start(user->getVolume(), user->getDistance());
                }
                if (buttons->at(1)->getGlobalBounds().contains(mousePosF))
                {
                    window->close();
                    for (int i = 0; i < audios->size(); i++)
                    {
                        audios->at(i)->stop();
                    }
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
    Database* db = Database::getInstance();
    User* user = db->selectInf(1);
    WorkWindow *settingsWindow = new WorkWindow(widthWindow, heightWindow, "Settings", "source/img/settings.jpg", user); 
    RenderWindow* settings = settingsWindow->getWindow();
    IntRect startPosition1(0, 0, 85, 85);
    vector<CustomButton*> buttons; //*?
    CustomButton exitButton(*(settingsWindow->window), "source/img/exitSettings.png", "source/img/exitSettings.png", startPosition1, -(width - 85), -(height - 85));
    buttons.push_back(&exitButton);
    settingsWindow->setButtons(&buttons);
    float volume=100;
    bool checkBoxValue = false;
    if (user != nullptr)
    {
        volume = user->getVolume();
        checkBoxValue = user->getDistance();
    }
    settingsWindow->progressbar = new ProgressBar(" ", 300, 30, 10, 50, "Music Volume", volume);
    settingsWindow->checkbox = new CheckBox(300, 200, "Distance", "V", checkBoxValue);
    settingsWindow->start();
    
}


void WorkWindow::startSettings()
{
    Database* db = Database::getInstance();
    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event))
        {
            Vector2i mousePos = Mouse::getPosition(*window);
            Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            if (event.type == Event::Closed)
            {
                saveSettings();
                window->close();
                createMain();
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
                if (progressbar->containBounds(mousePos.x, mousePos.y))
                {
                    progressbar->move(mousePos.x);
                    mainMusic->setVolume(progressbar->getVolume());
                    db->updateVolume(user->getIdUser(), progressbar->getVolume());
                }
            }
            if(event.type == Event::MouseButtonReleased)
            {
                if (buttons->at(0)->getGlobalBounds().contains(mousePosF))  
                {
                    saveSettings();
                    window->close();
                    createMain();
                }
                if (checkbox->containsBound(mousePos.x, mousePos.y))
                {
                    checkbox->changeChecked();
                    db->updateDistance(user->getIdUser(), checkbox->isChecked());
                }
                
            }
        }


        window->clear();
        window->draw(*background); //отрисовка 

        for (int i = 0; i < buttons->size(); i++)
        {
            buttons->at(i)->draw();
        }
        if (progressbar != nullptr)
        {
            window->draw(*progressbar);
        }
        if (checkbox != nullptr)
        {
            window->draw(*checkbox);
        }
        window->display(); // вывод на экран контента

    }
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

