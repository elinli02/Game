#include "WorkWindow.h"

WorkWindow::WorkWindow(int width, int height, string name, string pathBackground)
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
    RenderWindow window(VideoMode(width, height), name);
    Texture texture;
    if (!texture.loadFromFile(pathBackground))
        throw CustomException("File is not loaded!");
    //todo выполнить обработку спрайта и создать метод для кнопок и запуска окна, метод для музыки
}
