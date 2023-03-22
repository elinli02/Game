#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include "CustomButton.h"
#include "WorkWindow.h"

using namespace sf;

int main()
{
    WorkWindow::startApplication();
    
}

//void createWindow(Texture texture1)
//{
//    HWND hWnd1 = GetConsoleWindow();
//    ShowWindow(hWnd1, SW_HIDE);
//    RenderWindow window1(VideoMode(widthWindow, heightWindow), "Start window");
//    
//    Sprite sprite1(texture1);
//    while (window1.isOpen())
//    {
//        Event event1;
//        while (window1.pollEvent(event1))
//        {
//            if (event1.type == Event::Closed)
//                window1.close();
//        }
//        window1.clear();
//        window1.draw(sprite1);
//        window1.display();
//    }
//}