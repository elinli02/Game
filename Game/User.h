#pragma once
#include<iostream>
using namespace std;
//������������� ���� � ������ (ORM ������)
class User
{
    int id_user;
    string name;
    float volume;
    bool check_distance;
public:
    User(int id_user, string name, float volume, bool check_distance);
    int getIdUser();
    float getVolume();
    bool getDistance();
};

