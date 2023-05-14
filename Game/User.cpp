#include "User.h"

User::User(int id_user, string name, float volume, bool check_distance)
{
    this->id_user = id_user;
    this->name = name;
    this->volume = volume;
    this->check_distance = check_distance;
}

int User::getIdUser()
{
    return id_user;
}

float User::getVolume()
{
    return volume;
}

bool User::getDistance()
{
    return check_distance;
}
