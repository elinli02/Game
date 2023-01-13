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
    // todo ����������� �������� ��� ����, ���������� ������� ���� �� ����������� ��������
    // 3 ������� ��� ������� ����
    Sprite* background;
    vector<CustomButton*> buttons;
    vector<Music*> audios;
public:
    WorkWindow(int width, int height, string name, string pathBackground);
};

